#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m, h; cin>>n>>m>>h;
    vector<int> H(n + 1);
    vector<pii> g[n + 1];
    for(int i = 0; i < h; i++) {
        int x; cin>>x;
        H[x] = 1;
    }

    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    auto dij = [&] (int src) {
        vector<array<int, 2>> dist(n + 1, {INF, INF});
        set<array<int, 3>> st;
        dist[src][H[src]] = 0;
        st.insert({0, src, H[src]});
        while(sz(st)) {
            auto [d, u, f] = *st.begin();
            st.erase(st.begin());
            for(auto [v, w] : g[u]) {
                if(f) w /= 2;
                int ff = f | H[v];
                if(dist[u][f] + w < dist[v][ff]) {
                    if(dist[v][ff] != INF)
                        st.erase({dist[v][ff], v, ff});
                    dist[v][ff] = dist[u][f] + w;
                    st.insert({dist[v][ff], v, ff});
                }
            }
        }
        return dist;
    };

    auto dist1 = dij(1);
    auto dist2 = dij(n);

    int ans = INF;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, max(min(dist1[i][0], dist1[i][1]), min(dist2[i][0], dist2[i][1])));
    }

    cout<<(ans == INF ? -1 : ans)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}