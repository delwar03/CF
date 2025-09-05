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
const int N = 35;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[N][N];

int nCr(int n, int r) {
    if(n < r) return 0;
    if(r == 0) return 1;
    int &ans = dp[n][r];
    if(~ans) return ans;
    ans = nCr(n - 1, r) + nCr(n - 1, r - 1);
    return ans;
}

void solve() {
    int n, r; cin >> n >> r;
    memset(dp, -1, sizeof dp);
    cout << nCr(n, r) << endl;
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