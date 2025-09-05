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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[25][105], w[25], v[25];

int magic(int ind, int rem) {
    if(ind < 0) return 0;
    int &ans = dp[ind][rem];
    ans = magic(ind - 1, rem);
    if(rem - w[ind] >= 0)
        ans = max(ans, v[ind] + magic(ind - 1, rem - w[ind]));
    return ans;
}

void solve() {
    int N, W; cin >> N >> W;
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
    memset(dp, -1, sizeof dp);
    cout << magic(N - 1, W) << endl;
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