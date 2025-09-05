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
};

void solve() {
    int n; cin >> n;
    vector<Point> v(n);
    for(auto &[x, y] : v) cin >> x >> y;

    auto getArea = [&] (vector<Point>& poly) {
        int ret = 0, n = sz(poly);
        for(int i = 0; i < n; i++) ret += poly[i].x * poly[(i + 1) % n].y - poly[(i + 1) % n].x * poly[i].y;
        return abs(ret);
    };

    auto getCnt = [&] (Point& A, Point& B) {
        int dx = abs(A.x - B.x), dy = abs(A.y - B.y), g = gcd(dx, dy);
        // cerr << "(" << A.x << ", " << A.y << ") --- " <<  "(" << B.x << ", " << B.y << ") ==> " << g + 1 << endl;
        return g + 1;
    };

    int B = 0, A = getArea(v);
    for(int i = 0; i < n; i++) B += getCnt(v[i], v[(i + 1) % n]);
    B -= n;

    cout << (A - B  + 2) / 2 << " " << B << endl;
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