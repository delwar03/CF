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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    vector<pii> g[n + 1];
    for(int i = 0; i < m; i++) {
        int l, r, d; cin>>l>>r>>d;
        g[l - 1].push_back({r, r - l + 1 - d});
    }
    for(int i = 0; i < n; i++) g[i].push_back({i + 1, 1}), g[i + 1].push_back({i, 0});

    vector<int> dist(n + 1, INF);
    set<pii> st;
    dist[0] = 0;
    st.insert({0, 0});
    while(sz(st)) {
        auto [d, u] = *st.begin(); st.erase(st.begin());
        if(dist[u] < d) continue;
        for(auto [v, wt] : g[u]) {
            if(dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                st.insert({dist[v], v});
            }
        }
    }

    // for(int i = 0; i <= n; i++) cerr<<dist[i]<<" "; cerr<<endl;
    for(int i = 1; i <= n; i++) {
        cout<<(dist[i] == dist[i - 1] ? 1 : 0)<<" \n"[i == n];
    }
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