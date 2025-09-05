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

int curX;

struct Point {
    int x, y, id;

    bool operator < (const Point& him) const {
        return x == him.x ? y < him.y : x < him.x;
    }
};

struct Line {
    Point a, b;
    int id;

    double yAt(int x) {
        if(a.x == b.x) return a.y;
        return a.y + (x - a.x) * (a.y - b.y) / (a.x - b.x);
    } 
};

bool operator < (const Line& A, const Line& B) {
    return A.id != B.id;
}

void solve() {
    int n; cin >> n;
    vector<Line> v(n);
    vector<Point> event;
    int ct = 0;
    for(auto &[a, b, id] : v) {
        cin >> a.x >> a.y >> b.x >> b.y, id = a.id = b.id = ct++;
        if(!(a < b)) swap(a, b);
        event.push_back(a);
        event.push_back(b);
    }
    sort(event.begin(), event.end());

    pii ans = {-INF, -INF};
    set<Line> st;

    cerr << v[0].yAt(10);

    for(auto [x, y, i] : event) {
        curX = x;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("cowjump.in", "r")) {
        freopen("cowjump.in", "r", stdin);
        freopen("cowjump.out", "w", stdout);
    }

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}