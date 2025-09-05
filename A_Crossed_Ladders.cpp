#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define double long double
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
const double eps = 1e-8;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    double x, y, h; cin >> x >> y >> h;

    double lo = 0, hi = min(x, y);

    while(hi - lo > eps) {
        double mid = (lo + hi) / 2.0;
        double cur = 1 / (1 / sqrt(x * x - mid * mid) + 1 / sqrt(y * y - mid * mid));

        if(cur <= h) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(10) << hi << endl;
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