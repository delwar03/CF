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
    vector<int> v(n), pf(n);
    for(auto &x : v) cin>>x;
    for(int i = 0; i < n; i++) pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0) + v[i];

    vector dp(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) dp[i][i] = 0;

    for(int l = n - 1; l >= 0; l--) {
        for(int r = l + 1; r < n; r++) {
            int &ans = dp[l][r];
            for(int k = l; k < r; k++) {
                ans = min(ans, dp[l][k] + dp[k + 1][r] + pf[r] - (l - 1 >= 0 ? pf[l - 1] : 0LL));
            }
        }
    }

    cout<<dp[0][n - 1]<<endl;
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