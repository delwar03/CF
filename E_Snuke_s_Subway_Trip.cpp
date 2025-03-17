#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    vector<pair<int, int>> g[n + 1];
    while(m--) {
        int u, v, c; cin>>u>>v>>c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    vector<int> dp(n + 1, INF);
    deque<pair<int, int>> dq;
    dq.push_back({1, -1});
    dp[1] = 0;

    while(dq.size()) {
        auto [u, com] = dq.front();
        dq.pop_front();
        for(auto [v, c] : g[u]) {
            if(dp[v] > dp[u] + (c != com)) {
                dp[v] = dp[u] + (c != com);
                if(c != com) {
                    dq.push_back({v, c});
                } else {
                    dq.push_front({v, c});
                }
            }
        }
    }

    // for(int i = 1; i <= n; i++) cerr<<dp[i]<<" "; cerr<<endl;

    cout<<(dp[n] > n ? -1 : dp[n])<<endl;
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

/*
i/p: 
o/p: 
*/