#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    int n, m; cin>>n>>m;
    vector<pair<int, int>> g[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    int tar, ans;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

    function<void(int, int)> dfs = [&] (int u, int col) {
        if(u == tar) ans++;
        vis[u][col] = 1;
        for(auto it : g[u]) {
            int v = it.F, cur = it.S;
            if(!vis[v][cur]) {
                if(!col) {
                    dfs(v, cur);
                } else if(cur == col) {
                    dfs(v, cur);
                }
            }
        }
    };

    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        tar = v;
        ans = 0;
        vis.assign(n + 1, vector<int>(m + 1, 0));
        dfs(u, 0);
        cout<<ans<<endl;
    }
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