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
    int n; cin >> n;
    vector<int> v(n), cost(n), vals;
    for(auto &x : v) cin >> x, vals.push_back(x);
    for(auto &x : cost) cin >> x;

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto getId = [&] (int x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    };

    for(auto &x : v) x = getId(x);

    vector<int> dp(n + 1, cost[0]);
    dp[v[0]] = 0;
    
    for(int i = 1; i < n; i++) {
        vector<int> ndp(n + 1, INF);
        int mn = INF;
        for(int x = 1; x <= n; x++) {
            mn = min(mn, dp[x]);
            ndp[x] = min(ndp[x], (x != v[i] ? cost[i] : 0) + mn);
        }
        swap(dp, ndp);
    }

    // for(int x : dp) cerr << x << " "; cerr << endl;

    cout << *min_element(dp.begin(), dp.end()) << endl;
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