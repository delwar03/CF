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
    int n, q; cin >> n >> q;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n + 1), siz(n + 1), par(n + 1), st(n + 1), en(n + 1);
    int tt = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        siz[u] = 1;
        st[u] = ++tt;
        for(int v : g[u]) if(v ^ p) {
            dep[v] = 1 + dep[u];
            par[v] = u;
            dfs(v, u);
            siz[u] += siz[v];
        }
        en[u] = tt;
    };

    dfs(1, 0);

    vector<vector<int>> dp(32, vector<int>(n + 1));
    for(int i = 0; i < 32; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    auto kTh = [&] (int u, int k) {
        for(int i = 31; i >= 0; i--) if(k >> i & 1) u = dp[i][u];
        return u;
    };

    auto LCA = [&] (int u, int v) {
        if(dep[v] < dep[u]) swap(u, v);
        v = kTh(v, dep[v] - dep[u]);
        if(u == v) return u;
        for(int i = 31; i >= 0; i--) if(dp[i][u] ^ dp[i][v]) u = dp[i][u], v = dp[i][v];
        u = dp[0][u], v = dp[0][v];
        assert(u == v);
        return u;
    };

    auto dist = [&] (int u, int v) {
        return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
    };

    auto isAnc = [&] (int u, int v) {
        return st[u] <= st[v] && en[v] <= en[u];
    };

    auto onSeg = [&] (int a, int b, int c) {
        int lca = LCA(a, b);
        if(lca == c) return 1;
        return isAnc(c, a) ^ isAnc(c, b);
        // return dist(a, c) + dist(c, b) == dist(a, b);
    };

    while(q--) {
        int a, b, c; cin >> a >> b >> c;
        if(!onSeg(a, b, c)) {cout << 0 << endl; continue; }
        int ans = n;

        if(isAnc(c, a)) {
            int p = kTh(a, dep[a] - dep[c] - 1);
            ans -= siz[p];
        } else {
            ans -= n - siz[c];
        }

        if(isAnc(c, b)) {
            int p = kTh(b, dep[b] - dep[c] - 1);
            ans -= siz[p];
        } else {
            ans -= n - siz[c];
        }

        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}