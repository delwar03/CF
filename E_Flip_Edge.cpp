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
    int n, m, x; cin>>n>>m>>x;
    vector<int> g[n + 1], gT[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        gT[v].push_back(u);
    }

    vector<array<int, 2>> dp(n + 1, {INF, INF});
    set<array<int, 3>> st;
    st.insert({0, 1, 1}); // {d, u, f}
    dp[1][1] = 0;

    while(sz(st)) {
        auto [d, u, f] = *st.begin(); st.erase(st.begin());
        if(d != dp[u][f]) continue;
        if(f) {
            for(auto v : g[u]) {
                if(d + 1 < dp[v][f]) {
                    dp[v][f] = d + 1;
                    st.insert({dp[v][f], v, f});
                }
            }
        } else {
            for(auto v : gT[u]) {
                if(d + 1 < dp[v][f]) {
                    dp[v][f] = d + 1;
                    st.insert({dp[v][f], v, f});
                }
            }
        }
        
        if(d + x < dp[u][!f]) {
            dp[u][!f] = d + x;
            st.insert({dp[u][!f], u, !f});
        }
    }

    cout<<min(dp[n][0], dp[n][1])<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}