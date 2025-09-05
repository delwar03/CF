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
const double eps = 1e-6;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    double a, b, c, k;
    while(cin >> a >> b >> c >> k) {
        if(!a && !b && !c && !k) return;
        
        auto f = [&] (double d, int f) {
            return sqrt(a * a + d * d) + (f ? k : 1) * sqrt(b * b + (c - d) * (c - d));
        };

        double lo = 0, hi = c;
        while(hi - lo > eps) {
            double m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
            auto x1 = f(m1, 1), x2 = f(m2, 1);
            if(x1 < x2) {
                hi = m2;
            } else {
                lo = m1;
            }
        }

        cout << fixed << setprecision(10) << f(lo, 0) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}