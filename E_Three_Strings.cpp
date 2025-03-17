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
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    string a, b, c; cin>>a>>b>>c;
    int n = sz(a), m = sz(b);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    a = "#" + a;
    b = "#" + b;
    c = "#" + c;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i - 1 >= 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (a[i] != c[i + j]));
            if(j - 1 >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (b[j] != c[i + j]));
        }
    }

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= m; j++) {
    //         cerr<<dp[i][j]<<" ";
    //     } cerr<<endl;
    // }

    cout<<dp[n][m]<<endl;
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