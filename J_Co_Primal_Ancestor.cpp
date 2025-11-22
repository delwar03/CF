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
const int N = 5e4 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> di[N];

void solve() {
    int n; cin >> n;
    vector<int> val(n + 1), g[n + 1];
    int mx = 0;
    for(int i = 1; i <= n; i++) cin >> val[i], mx = max(mx, val[i]);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n + 1), par(n + 1), tin(n + 1), tout(n + 1);
    int tt = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        tin[u] = ++tt;
        for(auto v : g[u]) if(v ^ p) {
            par[v] = u;
            dep[v] = 1 + dep[u];
            dfs(v, u);
        }
        tout[u] = tt;
    };

    dfs(1, 0);

    auto getDiv = [&] (int x) {
        vector<int> ret = {1};
        for(int p : di[x]) {
            int k = sz(ret), tmp = x, cnt = 0;
            while(tmp % p == 0) tmp /= p, cnt++;
            int cur = 1;
            for(int j = 0; j < cnt; j++) {
                cur *= p;
                for(int i = 0; i < k; i++) ret.push_back(ret[i] * cur);
            }
        }
        return ret;
    };

    vector<int> mp_in[mx + 1], mp_out[mx + 1];
    for(int i = 1; i <= n; i++) {
        for(int d : getDiv(val[i])) {
            mp_in[d].push_back(tin[i]);
            mp_out[d].push_back(tout[i]);
        }
    }

    for(int i = 1; i <= mx; i++) if(sz(mp_in[i])) {
        sort(mp_in[i].begin(), mp_in[i].end());
        sort(mp_out[i].begin(), mp_out[i].end());
    }

    vector<vector<int>> dp(32, vector<int>(n + 1));
    for(int i = 0; i < 32; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    auto LCA = [&] (int u, int v) {
        if(dep[v] < dep[u]) swap(u, v);
        int k = dep[v] - dep[u];
        for(int i = 30; i >= 0; i--) if((k >> i) & 1) v = dp[i][v];
        if(u == v) return u;
        for(int i = 30; i >= 0; i--) if(dp[i][u] ^ dp[i][v]) u = dp[i][u], v = dp[i][v];
        u = dp[0][u], v = dp[0][v];
        assert(u == v);
        return u;
    };

    auto qur = [&] (int u, int v) {
        int lca = LCA(u, v), tot = dep[lca] + 1;

        auto getCnt = [&] (int x) {
            if(x > mx) return int(0);
            int cnt = 0;
            if(sz(mp_in[x])) cnt += upper_bound(mp_in[x].begin(), mp_in[x].end(), tin[lca]) - mp_in[x].begin();
            if(sz(mp_out[x])) cnt -= lower_bound(mp_out[x].begin(), mp_out[x].end(), tin[lca]) - mp_out[x].begin();
            return cnt;
        };

        vector<int> all;
        for(int d : di[val[u]]) all.push_back(d);
        for(int d : di[val[v]]) all.push_back(d);
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        int sub = 0, sz = sz(all), mask = (1LL << sz);
        for(int i = 1; i < mask; i++) {
            int cur = 1;
            for(int j = 0; j < sz; j++) if((i >> j) & 1) cur *= all[j];
            sub += (__builtin_popcountll(i) & 1 ? +1 : -1) * getCnt(cur);
        }

        return tot - sub;
    };

    int q, last = 0; cin >> q;
    while(q--) {
        int u, v; cin >> u >> v; u ^= last, v ^= last;
        // cerr << "u: " << u << ", v: " << v << endl;
        cout << (last = qur(u, v)) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        if(sz(di[i])) continue;
        for(int j = i; j < N; j += i) {
            di[j].push_back(i);
        }
    }

    // for(int i = 1; i <= 100; i++) {
    //     cerr << i << " -> ";
    //     for(int j : di[i]) cerr << j << " "; cerr << endl;
    // }

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}