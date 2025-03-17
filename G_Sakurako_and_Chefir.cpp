#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> dp(31, vector<int>(n + 1));

    vector<int> sz(n + 1), par(n + 1), dep(n + 1), centPar(n + 1), maxDist(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dep[v] = 1 + dep[u];
                par[v] = u;
                dfs(v, u);
                maxDist[u] = max(maxDist[u], 1 + maxDist[v]);
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
            if(k & (1 << i)) {
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

    auto getDist = [&] (int u, int v) {
        return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
    };

    function<int(int, int)> dfs1 = [&] (int u, int p) {
        sz[u] = 1;
        for(auto v : g[u]) {
            if((v ^ p) && !centPar[v]) {
                sz[u] += dfs1(v, u);
            }
        }
        return sz[u];
    };

    function<int(int, int, int)> dfs2 = [&] (int u, int p, int cur) {
        for(auto v : g[u]) {
            if((v ^ p) && !centPar[v]) {
                if(2 * sz[v] > cur) {
                    return dfs2(v, u, cur);
                }
            }
        }
        return u;
    };

    function<void(int, int)> magic = [&] (int u, int p) {
        int cent = dfs2(u, p, dfs1(u, p));
        centPar[cent] = p;
        for(auto v : g[cent]) {
            if(!centPar[v]) {
                magic(v, cent);
            }
        }
    };

    magic(1, -1);

    auto qur = [&] (int u, int k) {
        int ret = 0;
        for(int p = u; p >= 0; p = centPar[p]) {
            if(getDist(u, p) <= k) 
                ret = max(ret, getDist(u, p) + maxDist[p]);
        }
        return ret;
    };

    int q; cin>>q;
    while(q--) {
        int u, k; cin>>u>>k;
        cout<<qur(u, k)<<" ";
    } cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/