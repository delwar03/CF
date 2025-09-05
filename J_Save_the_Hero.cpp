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
const double PI = acos(-1.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
    double x, y;
};

void solve() {
    int n, m; double r; cin >> n >> m >> r;
    r /= 2;
    int p = (n + 1) / 2;
    double h = r * m / p;

    auto getAng = [&] (const Point& A, const Point& B, const Point& C) {
        double dot = (A.x - B.x) * (C.x - B.x) + (A.y - B.y) * (C.y - B.y);
        double lenBA = hypot(A.x - B.x, A.y - B.y), lenBC = hypot(C.x - B.x, C.y - B.y);
        if(lenBA == 0 || lenBC == 0) return (double) 0.0;
        double cosTheta = dot / (lenBA * lenBC);
        if(cosTheta < -1.0) cosTheta = -1.0;
        if(cosTheta > 1.0) cosTheta = 1.0;
        return acos(cosTheta);
    };

    Point A, B, C;
    double y = r * (m - 1) / p;
    A = {sqrt(r * r - y * y), y};
    B = {0, 0};
    y = r * m / p;
    C = {sqrt(r * r - y * y), y};

    double ang = getAng(A, B, C) , area = 0.5 * r * r * ang;
    area += 0.5 * h * sqrt(r * r - h * h);
    h -= r / p;
    area -= 0.5 * h * sqrt(r * r - h * h);

    cout << fixed << setprecision(2) << 2 * area << endl;
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