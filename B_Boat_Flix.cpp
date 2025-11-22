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
const double eps = 1e-6;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define double long double

void solve() {
    int n, k; cin >> n >> k;
    int d, x, y; cin >> d >> x >> y;

    if(x >= y) {
        cout << (double) d / x << endl;
        return;
    }
    if(k >= n) {
        cout << (double) d / y << endl;
        return;
    }
    
    cout << ((double) k / n) * ((double) d / y) + ((double)(n - k) / n) * ((double) d / x) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(10);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}