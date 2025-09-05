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
    int n, m; cin >> n >> m;
    vector<pii> g[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v; char c; cin >> u >> v >> c;
        g[u].push_back({v, c - 'a'});
        g[v].push_back({u, c - 'a'});
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    deque<pii> dq;
    dist[1][n] = 0;
    dq.push_back({1, n});
    int ans = INF;

    while(sz(dq)) {
        auto [u, v] = dq.front(); dq.pop_front();
        if(u == v) { ans = min(ans, 2 * dist[u][v]); break; }
        for(auto [uu, c] : g[v]) if(uu == u) { ans = min(ans, 2 * dist[u][v] + 1); break; }

        // cerr << "u: " << u << ", v: " << v << ", dist: " << dist[u][v] << endl;

        for(auto [uu, c1] : g[u]) {
            for(auto [vv, c2] : g[v]) if(c1 == c2) {
                if(dist[uu][vv] > 1 + dist[u][v]) {
                    dist[uu][vv] = 1 + dist[u][v];
                    dq.push_back({uu, vv});
                }
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
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