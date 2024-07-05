#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
const double eps = 1e-10;

void solve() {
    int n; cin>>n;
    vector<int> pos(n + 1);
    vector<int> g[n + 1], rev[n + 1];
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        pos[i] = x;
        g[i].push_back(x);
        rev[x].push_back(i);
    }

    vector<int> topo;

    vector<int> vis(n + 1, 0);

    function<void(int)> dfs1 = [&] (int u) {
        vis[u] = 1;
        for(auto v : g[u]) {
            if(!vis[v]) {
                dfs1(v);
            }
        }
        topo.push_back(u);
    };

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs1(i);
        }
    }

    reverse(topo.begin(), topo.end());

    vector<vector<int>> scc;
    vector<int> cur;
    vis.assign(n + 1, 0);

    function<void(int)> dfs2 = [&] (int u) {
        vis[u] = 1;
        for(auto v : rev[u]) {
            if(!vis[v]) {
                dfs2(v);
            }
        }
        cur.push_back(u);
    };

    for(auto u : topo) {
        if(!vis[u]) {
            cur.clear();
            dfs2(u);
            scc.push_back(cur);
        }
    }

    // for(auto it : scc) {
    //     for(auto u : it) cerr<<u<<" "; cerr<<endl;
    // }

    vector<int> dp(n + 1, 0);

    reverse(scc.begin(), scc.end());

    for(auto v : scc) {
        if(v.size() == 1) {
            if(v[0] == pos[v[0]]) {
                dp[v[0]] = 1;
            } else {
                dp[v[0]] = 1 + dp[pos[v[0]]];
            }
        } else {
            int sz = v.size();
            for(auto it : v) {
                dp[it] = sz;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i];
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