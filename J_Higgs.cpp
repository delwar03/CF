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
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<pii> g[n];
    vector<int> vals;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin>>u>>v>>w;
        g[--u].push_back({--v, w});
        g[v].push_back({u, w});
        vals.push_back(w);
    }

    vals.push_back(0);

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto f = [&] (int mid) {
        vector<int> dist(n, INF);
        priority_queue<pii> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(sz(pq)) {
            auto [d, u] = pq.top(); pq.pop();
            d = -d;
            if(d > dist[u]) continue;
            for(auto [v, wt] : g[u]) {
                if(dist[u] + (wt > mid) < dist[v]) {
                    dist[v] = dist[u] + (wt > mid);
                    pq.push({-dist[v], v});
                }
            }
        }
        return dist[n - 1] <= k;
    };
    
    int lo = 0, hi = sz(vals) - 1, best = -1;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(f(vals[mid])) {
            best = vals[mid];
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout<<best<<endl;
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