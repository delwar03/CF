#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> sz(n + 1), ord;

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u);
                sz[u] += sz[v];
            }
        }
        sz[u]++;
    };

    function<int(int, int)> dfs2 = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                if(2 * sz[v] > n)
                    return dfs2(v, u);
            }
        }
        return u;
    };

    function<void(int, int)> dfs3 = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs3(v, u);
            }
        }
        ord.push_back(u);
    };

    dfs(1, 0);
    int cent = dfs2(1, 0);
    dfs3(cent, 0);

    vector<pair<int, int>> ans;
    int len = n / 2;

    for(int i = 0; i < len; i++) {
        ans.push_back({ord[i], ord[i + len]});
    }

    assert(ans.size() == n / 2);

    for(auto it : ans) cout<<it.ff<<" "<<it.ss<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/