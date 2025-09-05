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

    auto getArea = [&] (vector<Point>& v) {
        int ret = 0, n = sz(v);
        for(int i = 0; i < n; i++) ret += v[i].x * v[(i + 1) % n].y - v[(i + 1) % n].x * v[i].y;
        return abs(ret);
    };

    auto getCnt = [&] (Point& A, Point& B) {
        int dx = A.x - B.x, dy = A.y - B.y;
        return gcd(dx, dy) + 1;
    };

    auto A = getArea(poly), B = -n;
    for(int i = 0; i < n; i++) B += getCnt(poly[i], poly[(i + 1) % n]);

    cout << (A - B + 2) / 2 << endl;
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