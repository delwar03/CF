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
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    int ans = 0;
    for(int m = 1; m <= min(n, 100); m++) {
        vector<int> pf(n), mn(n), mx(n);
        for(int i = 0; i < n; i++) pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0) + (v[i] >= m ? +1 : -1);
        for(int i = 0; i < n; i++) mn[i] = min((i - 1 >= 0 ? mn[i - 1] : 0), pf[i]);
        for(int i = n - 1; i >= 0; i--) mx[i] = max((i + 1 < n ? mx[i + 1] : -INF), pf[i]);
        for(int i = 0; i < n; i++) {
            if((i - 1 >= 0 ? mn[i - 1] : 0) <= pf[i] || (i - 1 >= 0 ? pf[i - 1] : 0) <= mx[i]) ans = max(ans, m - v[i]);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}