#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> g[n + 1];
    for(int i = 0; i < n; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sz(n + 1);
    vector<char> ans(n + 1, '#');

    function<int(int, int)> dfs = [&] (int u, int p) {
        sz[u] = 1;
        for(int v : g[u]) {
            if((v ^ p) && ans[v] == '#') {
                sz[u] += dfs(v, u);
            }
        }
        return sz[u];
    };

    function<int(int, int, int)> dfs2 = [&] (int u, int p, int cur) {
        for(auto v : g[u]) {
            if((v ^ p) && ans[v] == '#') {
                if(2 * sz[v] > cur) {
                    return dfs2(v, u, cur);
                }
            }
        }
        return u;
    };

    function<void(int, int, int)> magic = [&] (int u, int p, int f) {
        int cent = dfs2(u, p, dfs(u, p));
        ans[cent] = 'A' + f;
        for(int v : g[cent]) {
            if(ans[v] == '#') {
                magic(v, u, f + 1);
            }
        }
    };

    magic(1, 0, 0);
    for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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