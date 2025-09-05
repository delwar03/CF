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
const double eps = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
    double x, y;
};

void solve() {
    int n; cin >> n;
    vector<Point> poly(n);
    for(auto &[x, y] : poly) cin >> x >> y;
    Point pt; cin >> pt.x >> pt.y;

    Point C{0, 0};
    for(auto [x, y] : poly) C.x += x, C.y += y;
    C.x /= n, C.y /= n;
    sort(poly.begin(), poly.end(), [&] (const auto& A, const auto& B) {
        return atan2(C.y - A.y, C.x - A.x) < atan2(C.y - B.y, C.x - B.x);
    });

    auto getAng = [&] (const Point& A, const Point& B, const Point& C) {
        double ret = atan2(C.y - A.y, C.x - A.x) - atan2(C.y - B.y, C.x - B.x);
        if(ret > M_PI) ret -= 2 * M_PI;
        if(ret <= -M_PI) ret += 2 * M_PI;
        return ret;
    };

    auto isInside = [&] (Point& A, vector<Point>& poly) {
        int n = sz(poly);
        double sm = 0;

        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            sm += getAng(poly[i], poly[j], A);
        }
        if(sm < 0) sm = -sm;
        return abs(sm - 2 * M_PI) < eps;
    };

    cout << (isInside(pt, poly) ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}