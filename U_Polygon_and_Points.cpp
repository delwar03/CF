#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<Point, Point>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
    int x, y, idx;
};


void solve() {
    int n; cin >> n;
    vector<Point> poly(n);
    int ct = 0;
    for(auto &[x, y, idx] : poly) cin >> x >> y, idx = ct++;

    auto ccw = poly;

    sort(ccw.begin(), ccw.end(), [&] (const auto& A, const auto& B) {
        if(A.y ^ B.y) return A.y < B.y;
        return A.x < B.x;
    });

    auto ori = [&] (Point& A, Point& B, Point& C) {
        int x = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
        return (x == 0 ? 0 : x > 0 ? +1 : -1);
    };

    auto intersect = [&] (Point& A, Point& B, Point& C) {
        if(!ori(A, B, C)) {
            if(min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) 
            && min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y)) return 2;
        }
        if(A.y <= C.y && C.y < B.y && ori(A, B, C) == 1) return 1;
        if(B.y <= C.y && C.y < A.y && ori(B, A, C) == 1) return 1;
        return 0;
    };

    auto get = [&] (Point& A) {
        int lo = 0, hi = n, best = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(ccw[mid].y <= A.y) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if(best == -1) return int(0);

        int i = ccw[best].idx;
        if(max(poly[(i + 1) % n].y, poly[(i - 1 + n) % n].y) < A.y) return int(0);

        int j = poly[(i + 1) % n].y >= A.y ? (i + 1) % n : (i - 1 + n) % n;
        
        int x = intersect(poly[i], poly[j], A);
        if(x == 2) return int(2);
        int cnt = x;
        
        i = (best - 1 >= 0 ? ccw[best - 1].idx : ccw[best].idx), j = poly[(i + 1) % n].y >= A.y ? (i + 1) % n : (i - 1 + n) % n;

        // cerr << poly[i].x << " " << poly[i].y << endl;
        // cerr << poly[j].x << " " << poly[j].y << endl;

        x = intersect(poly[i], poly[j], A);
        if(x == 2) return int(2);
        cnt += x;

        return int(cnt & 1);
    };

    int q; cin >> q;
    while(q--) {
        Point A; cin >> A.x >> A.y;
        int x = get(A);
        cout << (x == 0 ? "OUT" : x == 1 ? "IN" : "ON") << endl;
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