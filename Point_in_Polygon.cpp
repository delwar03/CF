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

    bool operator == (const Point& him) const {
        return x == him.x && y == him.y;
    }

    friend istream& operator >> (istream& in, Point& p) {
        return in >> p.x >> p.y;
    }

    friend ostream& operator << (ostream& out, Point& p) {
        return out << p.x << " " << p.y;
    }
};

void solve() {
    int n, m; cin>>n>>m;
    vector<Point> poly(n);
    for(auto &pt : poly) cin >> pt;

    auto isInside = [&] (vector<Point>& poly, Point& p) {

        auto ori = [&] (const Point& A, const Point& B, const Point& C) {
            int cur = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
            return cur == 0 ? 0 : cur > 0 ? 1 : -1;
        };

        auto intersect = [&] (const Point& A, const Point& B, const Point& C) {
            // [Ay, By) coz for polygon vertices you ended-up counting twice
            if(A.y <= C.y && C.y < B.y && ori(A, B, C) == 1) return true;
            if(B.y <= C.y && C.y < A.y && ori(B, A, C) == 1) return true;
            return false;
        };

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n, o = ori(poly[i], poly[j], p);
            if(o == 0) {
                if(min(poly[i].x, poly[j].x) <= p.x && p.x <= max(poly[i].x, poly[j].x) 
                && min(poly[i].y, poly[j].y) <= p.y && p.y <= max(poly[i].y, poly[j].y)) return int(2);
            }
            cnt += intersect(poly[i], poly[j], p);
        }
        return int(cnt % 2);
    };

    while(m--) {
        Point p; cin>>p;
        int f = isInside(poly, p);
        cout << (f == 2 ? "BOUNDARY" : f ? "INSIDE" : "OUTSIDE") << endl;
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