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
    vector<int> col(n + 1);
    for(int i = 1; i <= n; i++) cin >> col[i];
    int ans = 0;
    map<pii, int> edges;
    vector<pii> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        edges[{u, v}] = edges[{v, u}] = c;
        if(col[u] ^ col[v]) {
            ans += c;
        }
    }

    vector<int> par(n + 1), sm(n + 1);
    map<int, int> mp[n + 1];

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto [v, c] : g[u]) if(v ^ p) {
            par[v] = u;
            dfs(v, u);
            sm[u] += c;
            mp[u][col[v]] += c;
        }
    };

    dfs(1, 0);

    while(q--) {
        int u, x; cin >> u >> x;

        ans -= sm[u] - mp[u][col[u]];
        mp[par[u]][col[u]] -= edges[{u, par[u]}];
        if(par[u] && col[u] != col[par[u]]) {
            ans -= edges[{u, par[u]}];
        }

        col[u] = x;

        ans += sm[u] - mp[u][col[u]];
        mp[par[u]][col[u]] += edges[{u, par[u]}];
        if(par[u] && col[u] != col[par[u]]) {
            ans += edges[{u, par[u]}];
        }
        cout << ans << endl;
    }
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