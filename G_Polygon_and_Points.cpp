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

struct Point {
    int x, y;
};

void solve() {
    int n; cin >> n;
    vector<Point> poly(n);
    for(auto &[x, y] : poly) cin >> x >> y;

    auto isInside = [&] (vector<Point>& v, Point& A) {

        auto ori = [&] (Point& A, Point& B, Point& C) {
            int x = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
            return x == 0 ? 0 : x > 0 ? +1 : -1;
        };

        int o = ori(v[0], v[1], A);
        if(o < 0) return 0;
        if(!o) {
            return min(v[0].x, v[1].x) <= A.x && A.x <= max(v[0].x, v[1].x)
                && min(v[0].y, v[1].y) <= A.y && A.y <= max(v[0].y, v[1].y) ? 2 : 0;
        }
        o = ori(v[0], v[n - 1], A);
        if(o > 0) return 0;
        if(!o) {
            return min(v[0].x, v[n - 1].x) <= A.x && A.x <= max(v[0].x, v[n - 1].x)
                && min(v[0].y, v[n - 1].y) <= A.y && A.y <= max(v[0].y, v[n - 1].y) ? 2 : 0;
        }

        int lo = 1, hi = n - 2, best = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(ori(v[0], v[mid], A) >= 0) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        assert(~best);
        
        o = ori(v[best], v[best + 1], A);
        return !o ? 2 : o > 0;
    };

    int q; cin >> q;
    while(q--) {
        Point P; cin >> P.x >> P.y;
        int f = isInside(poly, P);
        cout << (f == 2 ? "ON" : f ? "IN" : "OUT") << endl;
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