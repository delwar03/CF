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
    int n, h, l; cin>>n>>h>>l;
    vector<int> dp(n, INF), g[n];
    queue<pair<int, int>> q;
    for(int i = 0; i < h; i++) {
        int x; cin>>x;
        dp[x] = 0;
        q.push({x, 0});
    }

    while(l--) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    while(!q.empty()) {
        auto [u, wt] = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(dp[v] > wt + 1) {
                dp[v] = wt + 1;
                q.push({v, wt + 1});
            }
        }
    }

    // for(int i = 0; i < n; i++) cerr<<dp[i]<<" "; cerr<<endl;

    int mx = 0;
    for(int i = 0; i < n; i++) {
        mx = max(mx, dp[i]);
    }

    for(int i = 0; i < n; i++) {
        if(dp[i] == mx) {
            cout<<i<<endl;
            return;
        }
    }
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