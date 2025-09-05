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
const int INF = 1e12 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
int dp[15][15], arr[15][15];

int magic(int i, int j) {
    if(i >= n || j >= m) return -INF;
    if(i == n - 1 && j == m - 1) return arr[i][j];
    int &ans = dp[i][j];
    if(~ans) return ans;
    ans = arr[i][j] + magic(i + 1, j);
    ans = max(ans, arr[i][j] + magic(i, j + 1));
    return ans;
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
    memset(dp, -1, sizeof dp);
    cout << magic(0, 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}