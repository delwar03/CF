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
    int n, x, y; cin>>n>>x>>y;
    vector<int> g1[n + 1], g2[n + 1];
    set<pii> e1, e2;
    int m; cin>>m;
    while(m--) {
        int u, v; cin>>u>>v;
        if(u > v) swap(u, v);
        g1[u].push_back(v);
        g1[v].push_back(u);
        e1.insert({u, v});
    }
    cin>>m;
    while(m--) {
        int u, v; cin>>u>>v;
        if(u > v) swap(u, v);
        g2[u].push_back(v);
        g2[v].push_back(u);
        e2.insert({u, v});
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF)), vis(n + 1, vector<int>(n + 1, 0));
    dp[x][y] = 0;
    set<array<int, 3>> st;
    st.insert({0, x, y});
    while(!st.empty()) {
        auto [d, u, v] = *st.begin();
        st.erase(st.begin());
        if(vis[u][v]) continue;
        vis[u][v] = 1;
        for(auto v1 : g1[u]) {
            for(auto v2 : g2[v]) {
                if(dp[v1][v2] > d + abs(v1 - v2)) {
                    dp[v1][v2] = d + abs(v1 - v2);
                    st.insert({dp[v1][v2], v1, v2});
                }
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cerr<<dp[i][j]<<" \n"[j == n];
    //     }
    // }

    int ans = INF;
    for(auto [u, v] : e1) {
        if(e2.count({u, v})) {
            ans = min(ans, dp[u][u]);
            ans = min(ans, dp[v][v]);
        }
    }

    if(ans == INF) ans = -1;
    cout<<ans<<endl;
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