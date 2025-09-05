#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 100000007;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int binPow(int a, int b) {
    int ret = 1;
    while(b > 0) {
        if(b & 1) ret = 1LL * ret * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(1024);
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1, x; i <= m; i++) cin >> x, b[x] = 1;

    vector<vector<int>> dp(n + 1, vector<int>(1024, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 1024; j++) {
            dp[i][j] = (1LL * dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j] = (1LL * dp[i][j] + dp[i - 1][j ^ a[i]]) % mod;
        }
    }

    int ans = binPow(2, n);
    for(int i = 0; i < 1024; i++) if(b[i]) {
        ans = (1LL * ans - dp[n][i] + mod) % mod;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        cout<<"Case "<<tc<<": ";
        solve();
    }
}