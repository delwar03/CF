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
    vector<int> val(n + 1), g[n + 1];
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> st(n + 1), en(n + 1);
    vector<int> dep(n + 1);
    vector<vector<int>> xorr(n + 1, vector<int>(2));
    int timer = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        st[u] = ++timer;
        xorr[u][0] = val[u];
        for(auto v : g[u]) {
            if(v ^ p) {
                dep[v] = 1 + dep[u];
                dfs(v, u);
                xorr[u][0] ^= xorr[v][1];
                xorr[u][1] ^= xorr[v][0];
            }
        }
        en[u] = timer;
    };

    dfs(1, 0);

    int xr = 0;

    for(int i = 1; i <= n; i++) {
        if(dep[i] & 1) {
            xr ^= val[i];
        }
    }

    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        // cerr<<u<<" "<<v<<endl;
        if(st[u] <= st[v] && en[u] >= en[v]) {
            cout<<"INVALID"<<endl;
        } else {
            int f = dep[u] & 1, tmp = xr;
            if(f) tmp ^= xorr[u][0];
            else tmp ^= xorr[u][1];
            f = (dep[v] + 1) & 1;
            if(f) tmp ^= xorr[u][0];
            else tmp ^= xorr[u][1];

            cout<<(tmp ? "YES" : "NO")<<endl;
        }
    }
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