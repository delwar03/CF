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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x, --x;

    vector<pair<int, int>> g[n];
    for(int i = 0; i < n; i++) {
        if(i) g[i].push_back({i - 1, 0});
        g[i].push_back({b[i], a[i]});
    }

    vector<int> dp(n, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    dp[0] = 0;

    while(pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        for(auto [v, wt] : g[u]) {
            if(dp[v] > -d + wt) {
                dp[v] = -d + wt;
                pq.push({-dp[v], v});
            }
        }
    }

    int ans = 0, sm = 0;

    for(int i = 0; i < n; i++) {
        sm += a[i];
        ans = max(ans, sm - dp[i]);
    }

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

/*
i/p: 
o/p: 
*/