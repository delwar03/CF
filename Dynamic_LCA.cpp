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
    int n;
    while(cin >> n && n) {
        vector<int> g[n + 1];
        for(int i = 0; i < n - 1; i++) {
            int u, v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> par(n + 1), dep(n + 1), st(n + 1), en(n + 1);
        int tt = 0;

        function<void(int, int)> dfs = [&] (int u, int p) {
            st[u] = ++tt;
            for(int v : g[u]) if(v ^ p) {
                dep[v] = 1 + dep[u];
                par[v] = u;
                dfs(v, u);
            }
            en[u] = tt;
        };

        dfs(1, 0);

        vector<vector<int>> dp(31, vector<int>(n + 1));
        for(int i = 0; i < 31; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
            }
        }

        auto LCA = [&] (int u, int v) {
            if(dep[v] < dep[u]) u ^= v ^= u ^= v;
            int k = dep[v] - dep[u];
            for(int i = 30; i >= 0; i--) if(k >> i & 1) v = dp[i][v];
            if(u == v) return u;
            for(int i = 30; i >= 0; i--) if(dp[i][u] ^ dp[i][v]) u = dp[i][u], v = dp[i][v];
            u = dp[0][u], v = dp[0][v];
            assert(u == v);
            return u;
        };

        int q, root = 1; cin>>q;
        while(q--) {
            char op; cin>>op;
            if(op == '?') {
                int u, v; cin>>u>>v;
                int lca = LCA(u, v);
                if(st[lca] <= st[root] && st[root] <= en[lca]) {
                    int lu = LCA(u, root), lv = LCA(v, root);
                    cout<<(dep[lu] > dep[lv] ? lu : lv)<<endl;
                } else {
                    cout<<lca<<endl;
                }
            } else {
                int u; cin>>u;
                root = u;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("dynamic.in", "r")) {
        freopen("dynamic.in", "r", stdin);
        freopen("dynamic.out", "w", stdout);
    }

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}