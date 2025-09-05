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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
    int x, y;

    bool operator == (const Point& him) const {
        return x == him.x && y == him.y;
    }
};

void solve() {
    int n; cin>>n;
    vector<Point> v(n);
    for(auto &[x, y] : v) cin>>x>>y;
    
    auto ori = [&] (const Point& A, const Point& B, const Point& C) {
        int cur = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
        return cur == 0 ? 0 : cur > 0 ? 1 : -1;
    };

    auto dist = [&] (const Point& A, const Point& B) {
        int dx = A.x - B.x, dy = A.y - B.y;
        return dx * dx + dy * dy;
    };

    auto getHull = [&] (vector<Point>& v) {

        auto p0 = *min_element(v.begin(), v.end(), [&] (const auto& A, const auto& B) {
            return A.y < B.y || (A.y == B.y && A.x < B.x);
        });

        sort(v.begin(), v.end(), [&] (const auto& A, const auto& B) {
            int o = ori(p0, A, B);
            if(o == 0) return dist(p0, A) < dist(p0, B);
            return o > 0;
        });

        vector<Point> hull;
        for(auto &pt : v) {
            while(sz(hull) > 1 && ori(hull.end()[-2], hull.end()[-1], pt) <= 0) hull.pop_back();
            hull.push_back(pt);
        }
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        return hull;
    };

    auto hull = getHull(v);
    int m = sz(hull);

    double ang = 1e9;
    for(int j = 0; j < m; j++) {
        int i = (j - 1 + m) % m, k = (j + 1) % m;
        double d = atan2(hull[j].y - hull[i].y, hull[j].x - hull[i].x) - atan2(hull[j].y - hull[k].y, hull[j].x - hull[k].x);
        if(d < 0) d += 2 * M_PI;
        if(d < ang) ang = d;
    }

    cout<<fixed<<setprecision(10)<<ang * 180 / M_PI<<endl;
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