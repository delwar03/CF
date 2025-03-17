#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> dp(n + 1, 0);

    for(int i = 0; i < n; i++) {
        dp[i + 1] = 20 + dp[i];
        dp[i + 1] = min(dp[i + 1], 50 + dp[lower_bound(v.begin(), v.end(), v[i] - 89) - v.begin()]);
        dp[i + 1] = min(dp[i + 1], 120 + dp[lower_bound(v.begin(), v.end(), v[i] - 1439) - v.begin()]);
        
        cout<<dp[i + 1] - dp[i]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
