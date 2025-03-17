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
    string s, t; cin>>s>>t;
    if(n < m) {
        swap(s, t);
        swap(n, m);
    }

    // cerr<<s<<" "<<t<<endl;

    auto get = [&] (string s, string t) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = (s[0] == t[0]);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i - 1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(j - 1 >= 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if(s[i] == t[j]) {
                    if(i - 1 >= 0 && j - 1 >= 0)
                        dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
            }
        }
        // cerr<<"mx: "<<dp[n - 1][m - 1]<<endl;
        return m - dp[n - 1][m - 1];
    };

    int ans = n + get(s, t);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    ans = min(ans, n + get(s, t));

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}

/*
i/p: 
o/p: 
*/