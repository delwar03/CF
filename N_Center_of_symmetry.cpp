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
    double x, y;
    bool operator < (const Point& him) const {
        return x < him.x || (x == him.x && y < him.y);
    }
};

void solve() {
    int n; cin >> n;
    vector<Point> v(n);
    map<Point, int> mp;
    for(auto &[x, y] : v) cin >> x >> y, mp[{x, y}] = 1;

    Point Mid{0, 0};
    for(auto [x, y] : v) Mid.x += x, Mid.y += y;
    Mid.x /= n, Mid.y /= n;

    for(int i = 0; i < n; i++) {
        Point mirror;
        mirror.x = 2 * Mid.x - v[i].x, mirror.y = 2 * Mid.y - v[i].y;
        if(!mp.count(mirror)) {cout << "no" << endl; return; }
    }
    cout << "yes" << endl;
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