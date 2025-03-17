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
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector dp(n, vector<int>(n));

    for(int l = n - 1; l >= 0; l--) {
        for(int r = l + 1; r < n; r++) {
            int &ans = dp[l][r];
            for(int k = l; k < r; k++) ans = max(ans, dp[l][k] + dp[k + 1][r]);
            for(int k = l + 1; k < r; k++) ans = max(ans, dp[l + 1][k - 1] + dp[k + 1][r - 1] + v[l] * v[k] * v[r]);
        }
    }

    cout<<dp[0][n - 1]<<endl;
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