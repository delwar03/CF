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

int di[N], F[N];

void solve() {
    int n; cin >> n;
    vector<int> val(n + 1), xor_val(n + 1), g[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
        int tmp = abs(val[i]);
        while(tmp > 1) {
            int p = di[tmp];
            while(tmp % p == 0) xor_val[i] ^= F[p], tmp /= p;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n + 1), cntNeg(n + 1), cntZero(n + 1), par(n + 1), prod(n + 1);
    prod[1] = xor_val[1];
    cntNeg[1] = val[1] < 0;
    cntZero[1] = val[1] == 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) if(v ^ p) {
            prod[v] = prod[u] ^ xor_val[v];
            dep[v] = 1 + dep[u];
            cntNeg[v] = cntNeg[u] + (val[v] < 0);
            cntZero[v] = cntZero[u] + (val[v] == 0);
            par[v] = u;
            dfs(v, u);
        }
    };

    dfs(1, 0);

    vector<vector<int>> dp(30, vector<int>(n + 1));
    for(int i = 0; i < 30; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    auto LCA = [&] (int u, int v) {
        if(dep[v] < dep[u]) swap(u, v);
        int k = dep[v] - dep[u];
        for(int i = 29; i >= 0; i--) if((k >> i) & 1) v = dp[i][v];
        if(u == v) return u;
        for(int i = 29; i >= 0; i--) if(dp[i][u] ^ dp[i][v]) u = dp[i][u], v = dp[i][v];
        u = dp[0][u], v = dp[0][v];
        assert(u == v);
        return u;
    };

    auto qur = [&] (int u, int v) {
        int lca = LCA(u, v);
        int zero = cntZero[u] + cntZero[v] - cntZero[lca] - cntZero[par[lca]];
        if(zero > 0) return true;
        int neg = cntNeg[u] + cntNeg[v] - cntNeg[lca] - cntNeg[par[lca]];
        if(neg & 1) return false;
        
        int cur = prod[u] ^ prod[v] ^ xor_val[lca];
        return cur == 0;
    };

    int q; cin >> q;

    while(q--) {
        int u, v; cin >> u >> v;
        cout << (qur(u, v) ? "Yes" : "No") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    di[1] = 1;
    for(int i = 2; i < N; i++) {
        if(di[i]) continue;
        for(int j = i; j < N; j += i) {
            if(!di[j]) di[j] = i;
        }
    }

    for(int i = 1; i < N; i++) F[i] = rng() % mod;

    // for(int i = 1; i <= 100; i++) cerr << i << " " << di[i] << endl;

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}