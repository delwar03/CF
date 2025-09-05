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
    double x, y;
    bool operator == (const Point& him) const {
        return x == him.x && y == him.y;
    }
};

void solve() {
    int n; cin>>n;
    vector<Point> v(n);
    for(auto &[x, y] : v) cin>>x>>y;

    auto getArea = [&] (vector<Point>& v) {
        int n = sz(v);
        Point C{0, 0};
        for(auto [x, y] : v) C.x += x, C.y += y;
        C.x /= n, C.y /= n;
        sort(v.begin(), v.end(), [&] (const auto& A, const auto& B) {
            return atan2(C.y - A.y, C.x - A.x) < atan2(C.y - B.y, C.x - B.x);
        });
        double ret = 0;
        for(int i = 0; i < n; i++) ret += v[i].x * v[(i + 1) % n].y - v[(i + 1) % n].x * v[i].y;
        if(ret < 0) ret = -ret;
        return ret / 2.0;
    };

    cout<<fixed<<setprecision(10)<<getArea(v)<<endl;
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