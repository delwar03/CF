#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> g[n + 1];
    for(int i = 1; i <= m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    vector<int> vis(n + 1, 0);

    function<void(int)> dfs = [&] (int u) {
        vis[u] = 1;
        for(auto it : g[u]) {
            int v = it[0], wt = it[1];
            if(!vis[v]) {
                dfs(v);
            }
        }
    };

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            ans++;
        }
    }

    cout<<ans<<endl;
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