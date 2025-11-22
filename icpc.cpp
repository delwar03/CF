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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; string s; cin >> n >> s;
    int one = count(s.begin(), s.end(), '1'), zero = n - one;
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    function<int(int, int)> magic = [&] (int ind, int cnt) {
        if(ind == n) return int(0);
        int &ans = dp[ind][cnt];
        if(~ans) return ans;
        ans = 0;

        if(cnt) {
            if(ind - cnt + 1 <= zero)
                (ans += magic(ind + 1, cnt)) %= mod;
            if(cnt + 1 <= one)
                (ans += (ind - cnt) + magic(ind + 1, cnt + 1)) %= mod;
        } else {
            if(ind - cnt + 1 <= zero)
                (ans += magic(ind + 1, cnt)) %= mod;
            if(cnt + 1 <= one)
                (ans += ((mod - ind) * zero % mod)  + magic(ind + 1, cnt + 1)) %= mod;
        }

        return ans;
    };

    cout << magic(0, 0) << endl;
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