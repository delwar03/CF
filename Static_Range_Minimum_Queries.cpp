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

struct SparseTable {
    int n;
    vector<int> val;
    vector<vector<int>> dp;

    SparseTable(vector<int> v) : val(v), n(sz(v)) {
        dp = vector<vector<int>>(n, vector<int>(32));
        for(int j = 0; j < 32; j++) {
            for(int i = 0; i + (1LL << j) - 1 < n; i++) {
                dp[i][j] = (j == 0 ? val[i] : min(dp[i][j - 1], dp[i + (1LL << (j - 1))][j - 1]));
            }
        }
    }

    int qur(int l, int r) {
        int len = r - l + 1, k = 0;
        while((1LL << (k + 1)) <= len) k++;
        return min(dp[l][k], dp[r - (1LL << k) + 1][k]);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    SparseTable st(v);

    while(q--) {
        int l, r; cin >> l >> r; --l, --r;
        cout << st.qur(l, r) << endl;
    }
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