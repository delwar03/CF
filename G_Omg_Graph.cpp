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
    int n, m; cin>>n>>m;
    vector<pii> g[n];
    vector<array<int, 3>> edges;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin>>u>>v>>w;
        g[--u].push_back({--v, w});
        g[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    auto get = [&] (int src) {
        vector<int> in(n), dist(n, INF);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        in[src] = 1;

        while(sz(q)) {
            auto u = q.front(); q.pop();
            in[u] = 0;
            for(auto [v, w] : g[u]) {
                if(max(dist[u], w) < dist[v]) {
                    dist[v] = max(dist[u], w);
                    if(!in[v]) q.push(v), in[v] = 1;
                }
            }
        }
        dist[src] = INF;
        return dist;
    };

    auto d1 = get(0);
    auto d2 = get(n - 1);

    // for(auto i : d1) cerr<<i<<" "; cerr<<endl;
    // for(auto i : d2) cerr<<i<<" "; cerr<<endl;

    assert(d1[n - 1] == d2[0]);

    int ans = 2 * d1[n - 1];

    for(auto [u, v, w] : edges) {
        ans = min(ans, w + max(d1[u], d2[v]));
        ans = min(ans, w + max(d2[u], d1[v]));
    }

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