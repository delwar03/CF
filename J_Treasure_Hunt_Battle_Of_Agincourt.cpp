#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(auto &x : v) for(auto &y : x) cin >> y, --y;
    
    vector<vector<int>> dp(n, vector<int>(m, -INF));
    
    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = max({dp[i][j], v[i][j] + (i - 1 >= 0 ? dp[i - 1][j] : 0), v[i][j] + (j - 1 >= 0 ? dp[i][j - 1] : 0)});
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}