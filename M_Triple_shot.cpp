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
const double INF = 1e18;
const double eps = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
    double x, y;
    Point(): x(0.0), y(0.0) {}
    Point(double xx, double yy): x(xx), y(yy) {}
};

struct Line {
    double m, c; // m == INF -> x = c
    Point Intersect (Line& him) {
        Point ret;
        if(abs(m - INF) < eps && abs(him.m - INF) < eps) {
            ret.x = INF, ret.y = INF;
        } else if(abs(m - INF) < eps) {
            ret.x = c, ret.y = him.m * ret.x + him.c;
        } else if(abs(him.m - INF) < eps) {
            ret.x = him.c, ret.y = m * ret.x + c;
        } else {
            ret.x = (c - him.c) / (him.m - m), ret.y = m * ret.x + c;
        }
        return ret;
    }
};

int ori(Point& A, Point& B, Point& C) {
    auto cur = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if(abs(cur - 0.0) < eps) return 0;
    return cur > 0 ? +1 : -1;
}

void solve() {
    Point A, B, C;
    while(cin >> A.x) {
        cin >> A.y >> B.x >> B.y >> C.x >> C.y;
        if(!ori(A, B, C)) {cout << "Impossible" << endl; continue; }

        Point Mid = Point((A.x + B.x) / 2, (A.y + B.y) / 2);

        Line L1, L2;
        L1.m = (abs(B.y - A.y) < eps ? INF : (A.x - B.x) / (B.y - A.y));
        L1.c = (abs(L1.m - INF) < eps ? Mid.x : Mid.y - L1.m * Mid.x);

        // cerr << L1.m << " " << L1.c << endl;
        
        Mid = Point((A.x + C.x) / 2, (A.y + C.y) / 2);
        L2.m = (abs(C.y - A.y) < eps ? INF : (A.x - C.x) / (C.y - A.y));
        L2.c = (abs(L2.m - INF) < eps ? Mid.x : Mid.y - L2.m * Mid.x);

        auto ans = L1.Intersect(L2);

        if(abs(ans.x - INF) < 0 || abs(ans.y - INF) < 0) {cout << "Impossible" << endl; continue; }

        cout << fixed << setprecision(10);
        cout << ans.x << " " << ans.y << endl;
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