#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t
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

using ll = int64_t;

struct Point {
    int x, y;
};

struct Line {
    Point a, b;

    bool intersect(const Line& him) const {

        auto ori = [&] (const Point& A, const Point& B, const Point& C) {
            ll cur = 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
            return cur == 0 ? 0 : cur > 0 ? +1 : -1;
        };

        if(ori(a, b, him.a) == ori(a, b, him.b)) return false;
        if(ori(him.a, him.b, a) == ori(him.a, him.b, b)) return false;
        return true;
    }
};

void solve() {
    int s, k, w;
    while(cin >> s >> k >> w) {
        vector<Point> v(k);
        for(auto &[x, y] : v) cin >> x >> y;
        vector<Line> seg(w);
        for(auto &[a, b] : seg) cin >> a.x >> a.y >> b.x >> b.y;

        auto get = [&] (int id) {

            auto chk = [&] (const Point& a, const Point& b) {
                Line cur{a, b};
                for(auto &x : seg) if(cur.intersect(x)) return false;
                return true;
            };

            int ret = 0;
            for(int i = 0; i < k; i++) if(i ^ id) {
                ret += chk(v[id], v[i]);
            }
            return ret;
        };

        for(int i = 0; i < s; i++) {
            cout << get(i) << endl;
        }
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