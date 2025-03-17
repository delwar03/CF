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
    int n; cin>>n;
    vector<string> v(2);
    for(auto &x : v) cin>>x;
    vector<vector<int>> dp(2, vector<int>(n, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            // AJJAJJA
            // AJAAAJA
            if(j - 1 >= 0 && j + 1 < n) {
                cnt = 0;
                for(int k : {j - 1, j, j + 1}) cnt += (v[i][k] == 'A');
                dp[i][j] = max(dp[i][j], (j - 2 >= 0 ? dp[i][j - 2] : 0) + (cnt >= 2));
            }
            if(i == 0) {
                if(j - 1 >= 0) {
                    cnt = 0;
                    cnt += (v[i][j] == 'A');
                    cnt += (v[i][j - 1] == 'A');
                    cnt += (v[i + 1][j] == 'A');
                    dp[i][j] = max(dp[i][j], (j - 2 >= 0 ? dp[i][j - 2] : 0) + (cnt >= 2));
                }
                if(j + 1 < n) {
                    cnt = 0;
                    cnt += (v[i][j] == 'A');
                    cnt += (v[i][j - 1] == 'A');
                    cnt += (v[i + 1][j] == 'A');
                    dp[i][j] = max(dp[i][j], (j - 2 >= 0 ? dp[i][j - 2] : 0) + (cnt >= 2));
                }
            } else {

            }
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