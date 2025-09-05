#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin>>n>>q;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n + 1), par(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) if(v ^ p) {
            dep[v] = 1 + dep[u];
            par[v] = u;
            dfs(v, u);
        }
    };

    dfs(1, 0);

    vector<vector<int>> dp(32, vector<int>(n + 1));
    for(int i = 0; i < 32; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    auto LCA = [&] (int u, int v) {
        if(dep[v] < dep[u]) u ^= v ^= u ^= v;
        int k = dep[v] - dep[u];
        for(int i = 31; i >= 0; i--) if(k >> i & 1) v = dp[i][v];
        if(u == v) return u;
        for(int i = 31; i >= 0; i--) if(dp[i][u] ^ dp[i][v]) u = dp[i][u], v = dp[i][v];
        u = dp[0][u], v = dp[0][v];
        assert(u == v);
        return u;
    };

    auto dist = [&] (int u, int v) {
        return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
    };

    vector<int> centPar(n + 1), siz(n + 1);

    function<int(int, int)> dfs1 = [&] (int u, int p) {
        siz[u] = 1;
        for(auto v : g[u]) if((v ^ p) && !centPar[v]) {
            siz[u] += dfs1(v, u);
        }
        return siz[u];
    };

    function<int(int, int, int)> dfs2 = [&] (int u, int p, int cur) {
        for(auto v : g[u]) if((v ^ p) && !centPar[v]) {
            if(2 * siz[v] > cur) return dfs2(v, u, cur);
        }
        return u;
    };

    function<void(int, int)> magic = [&] (int u, int p) {
        int cent = dfs2(u, p, dfs1(u, p));
        centPar[cent] = p;
        for(auto v : g[cent]) if(!centPar[v]) magic(v, cent);
    };

    magic(1, -1);

    vector<int> ans(n + 1, INF);

    auto upd = [&] (int u) {
        for(int p = u; ~p; p = centPar[p]) {
            ans[p] = min(ans[p], dist(u, p));
        }
    };

    auto qur = [&] (int u) {
        int ret = INF;
        for(int p = u; ~p; p = centPar[p]) {
            ret = min(ret, ans[p] + dist(u, p));
        }
        return ret;
    };

    upd(1);

    while(q--) {
        int t, u; cin>>t>>u;
        if(t == 1) {
            upd(u);
        } else {
            cout<<qur(u)<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}