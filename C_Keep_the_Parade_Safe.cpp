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
};

void solve() {
    int n; cin>>n;
    vector<Point> bad(n);
    for(auto &[x, y] : bad) cin>>x>>y;
    int m; cin>>m;
    vector<Point> v(m);
    for(auto &[x, y] : v) cin>>x>>y;

    auto ori = [&] (const auto& A, const auto& B, const auto& C) {
        int cur = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
        return cur == 0 ? 0LL : cur > 0 ? 1LL : -1LL;
    };

    auto dist = [&] (const auto& A, const auto& B) {
        int dx = A.x - B.x, dy = A.y - B.y;
        return dx * dx + dy * dy;
    };

    auto getHull = [&] (vector<Point>& v) {
        auto p0 = *min_element(v.begin(), v.end(), [&] (const auto& A, const auto& B) {
            return A.y < B.y;
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

        return hull;
    };

    auto hull = getHull(bad);
    if(sz(hull) <= 3) {cout<<0<<endl; return; }

    auto isInside = [&] (const Point& cur, const vector<Point>& hull) {
        
    };

    int cnt = 0;
    for(auto &pt : v) cnt += isInside(pt, hull);
    cout<<cnt<<endl;
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