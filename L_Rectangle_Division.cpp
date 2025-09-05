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
};

void solve() {
    Point A, P; double r, c; cin >> A.x >> A.y >> r >> c >> P.x >> P.y;
    Point C{A.x + c / 2, A.y + r / 2};
    double y1 = C.y + (A.x - C.x) * (C.y - P.y) / (C.x - P.x);
    vector<Point> ans;
    if(A.y <= y1 && y1 <= A.y + r) {
        ans.push_back({A.x, y1});
        ans.push_back({2 * C.x - ans[0].x, 2 * C.y - ans[0].y});
    } else {
        double x1 = C.x + (A.y - C.y) * (C.x - P.x) / (C.y - P.y);
        ans.push_back({x1, A.y});
        ans.push_back({2 * C.x - ans[0].x, 2 * C.y - ans[0].y});
    }

    cout << fixed << setprecision(10);
    sort(ans.begin(), ans.end(), [&] (const auto& A, const auto& B) {
        return A.x < B.x || (A.x == B.x && A.y < B.y);
    });
    for(auto [x, y] : ans) cout << x << " " << y << endl;
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