#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[31][N];

void solve() {
    int n, q; cin>>n>>q;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> par(n + 1), dep(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dep[v] = dep[u] + 1;
                par[v] = u;
                dfs(v, u);
            }
        }
    };

    dfs(1, 0);

    for(int i = 0; i < 31; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    auto LCA = [&] (int u, int v) {
        if(dep[v] < dep[u]) swap(u, v);
        int k = dep[v] - dep[u];
        for(int i = 30; i >= 0; i--) {
            if((k >> i) & 1) {
                v = dp[i][v];
            }
        }

        if(u == v) return u;

        for(int i = 30; i >= 0; i--) {
            if(dp[i][u] != dp[i][v]) {
                u = dp[i][u];
                v = dp[i][v];
            }
        }

        u = dp[0][u];
        v = dp[0][v];

        assert(u == v);

        return u;
    };

    auto dist = [&] (int u, int v) {
        return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
    };

    vector<int> sz(n + 1), cent_par(n + 1);

    function<int(int, int)> dfs1 = [&] (int u, int p) {
        sz[u] = 1;
        for(auto v : g[u]) {
            if((v ^ p) && !cent_par[v]) {
                sz[u] += dfs1(v, u);
            }
        }
        return sz[u];
    };

    function<int(int, int, int)> dfs2 = [&] (int u, int p, int cur) {
        for(auto v : g[u]) {
            if((v ^ p) && !cent_par[v]) {
                if(2 * sz[v] > cur) {
                    return dfs2(v, u, cur);
                }
            }
        }
        return u;
    };

    function<void(int, int)> magic = [&] (int u, int p) {
        int cent = dfs2(u, p, dfs1(u, p));
        cent_par[cent] = p;
        for(auto v : g[cent]) {
            if(!cent_par[v]) {
                magic(v, cent);
            }
        }
    };

    magic(1, -1);

    vector<int> ans(n + 1, INF);

    auto upd = [&] (int u) {
        int p = u;
        while(1) {
            ans[p] = min(ans[p], dist(u, p));
            if(cent_par[p] == -1) break;
            p = cent_par[p];
        }
    };

    auto qur = [&] (int u) {
        int p = u, cur = INF;
        while(1) {
            cur = min(cur, ans[p] + dist(u, p));
            if(cent_par[p] == -1) break;
            p = cent_par[p];
        }
        return cur;
    };

    upd(1);
    
    while(q--) {
        int ty, u; cin>>ty>>u;
        if(ty == 1) {
            upd(u);
        } else {
            cout<<qur(u)<<endl;
        }
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