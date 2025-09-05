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

struct DSU {
    vector<int> par, siz;
    
    DSU(int n) {
        par = vector<int>(n + 1);
        siz = vector<int>(n + 1, 1);
        iota(par.begin(), par.end(), 0LL);
    }

    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return false;
        if(siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for(auto &[w, u, v] : edges) cin >> u >> v >> w;
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<pii> g[n + 1];
    for(auto [w, u, v] : edges) {
        if(dsu.join(u, v)) {
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
    }

    vector<int> par(n + 1), dep(n + 1), sm(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto [v, w] : g[u]) if(v ^ p) {
            dep[v] = dep[u] + 1, par[v] = u;
            sm[v] = sm[u] + w;
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
        if(dep[v] < dep[u]) swap(u, v);
        int k = dep[v] - dep[u];
        for(int i = 31; i >= 0; i--) if(k >> i & 1) v = dp[i][v];
        if(u == v) return u;
        for(int i = 31; i >= 0; i--) if(dp[i][u] ^ dp[i][v]) {
            u = dp[i][u];
            v = dp[i][v];
        }
        u = dp[0][u];
        v = dp[0][v];
        assert(u == v);
        return u;
    };

    auto dist = [&] (int u, int v) {
        return sm[u] + sm[v] - 2 * sm[LCA(u, v)];
    };

    for(auto [w, u, v] : edges) {
        if(w < dist(u, v)) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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