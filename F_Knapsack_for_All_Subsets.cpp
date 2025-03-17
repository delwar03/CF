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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, s; cin>>n>>s;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) ret = (ret * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ret;
    };

    auto inv = [&] (int a) {
        return binPow(a, mod - 2);
    };

    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    dp[0][0] = binPow(2, n);

    int inv2 = inv(2);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= s; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= mod;
            if(j + v[i] <= s) {
                dp[i + 1][j + v[i]] += (dp[i][j] * inv2) % mod;
                dp[i + 1][j] %= mod;
            }
        }
    }

    cout<<dp[n][s]<<endl;
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