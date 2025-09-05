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
    int x, y, idx;
};

void solve() {
    int n; cin>>n;
    vector<Point> poly(n);
    for(int i = 0; i < n; i++) cin >> poly[i].x >> poly[i].y, poly[i].idx = i + 1;

    auto n_poly = poly;

    auto ori = [&] (const Point& A, const Point& B, const Point& C) {
        int cur = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
        return cur == 0 ? 0 : cur > 0 ? 1 : -1;
    };
    
    auto dist = [&] (const Point& A, const Point& B) {
        int dx = A.x - B.x, dy = A.y - B.y;
        return dx * dx + dy * dy;
    };

    auto getHull = [&] (vector<Point>& poly) {
        auto p0 = *min_element(poly.begin(), poly.end(), [&] (const auto& A, const auto& B) {
            return A.y < B.y || (A.y == B.y && A.x < B.x);
        });
        sort(poly.begin(), poly.end(), [&] (const auto& A, const auto& B) {
            auto o = ori(p0, A, B);
            if(!o) return dist(p0, A) < dist(p0, B);
            return o > 0;
        });

        vector<Point> hull;
        for(auto pt : poly) {
            while(sz(hull) > 1 && ori(hull.end()[-2], hull.end()[-1], pt) <= 0) hull.pop_back();
            hull.push_back(pt);
        }

        return hull;
    };

    auto hull = getHull(poly);

    vector<bool> vis(n + 1);
    for(auto [x, y, idx] : hull) vis[idx] = 1;

    int id = -1;
    for(int i = 1; i <= n; i++) if(!vis[i]) {id = i; break; }
    if(id == -1) {cout<<-1<<endl; return; }

    for(int i = 1; i + 1 < sz(hull); i++) {
        int ct = ori(hull[0], hull[i], n_poly[id - 1]);
        ct += ori(hull[i], hull[i + 1], n_poly[id - 1]);
        ct += ori(hull[i + 1], hull[0], n_poly[id - 1]);
        if(ct == 3) {
            cout<<id<<" "<<hull[0].idx<<" "<<hull[i].idx<<" "<<hull[i + 1].idx<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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