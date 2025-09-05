#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    int n; cin>>n;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n + 1), siz(n + 1), par(n + 1), lf;
    function<void(int, int)> dfs = [&](int u, int p) {
        siz[u] = 1;
        int f = 1;
        for(auto v : g[u]) if(v ^ p) {
            dep[v] = dep[u] + 1;
            par[v] = u;
            dfs(v, u);
            siz[u] += siz[v];
            f = 0;
        }
        if(f) lf.push_back(u);
    };

    dfs(1, 0);

    vector<vector<int>> dp(32, vector<int>(n + 1));
    for(int i = 0; i < 32; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]];
        }
    }

    auto LCA = [&] (int u, int v) {
        if(dep[v] < dep[u]) swap(u, v);
        int k = dep[v] - dep[u];
        for(int i = 31; i >= 0; i--) if(k >> i & 1) v = dp[i][v];
        if(u == v) return u;
        for(int i = 31; i >= 0; i--) {
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

    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) (ret *= a) %= mod;
            (a *= a) %= mod;
            b >>= 1;
        }
        return ret;
    };

    if(sz(lf) > 2) {cout<<0<<endl; return; }
    if(sz(lf) == 1) {cout<<binPow(2, n)<<endl; return; }

    int u = lf[0], v = lf[1], lca = LCA(u, v);

    if(dep[u] == dep[v]) {cout<<binPow(2, dep[lca] + 2)<<endl; return; }

    int cur = max(dep[u], dep[v]) - min(dep[u], dep[v]) - 1;
    int ans = (binPow(2, cur) + binPow(2, cur + 1)) % mod;
    (ans *= binPow(2, dep[lca] + 1)) %= mod;

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}