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

struct Stick {
    Point a, b;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<Stick> v(n);
    for(auto &[a, b] : v) cin >> a.x >> a.y >> b.x >> b.y;

    vector<int> par(n), siz(n, 1);
    iota(par.begin(), par.end(), 0LL);

    function<int(int)> find = [&] (int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    };

    auto join = [&] (int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return false;
        if(siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        return true;
    };

    auto same = [&] (int u, int v) {
        return find(u) == find(v);
    };

    auto intersect = [&] (Stick& A, Stick& B) {

        auto ori = [&] (Point& A, Point& B, Point& C) {
            int x = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
            return x == 0 ? 0 : x > 0 ? +1 : -1;
        };

        int x1 = ori(A.a, A.b, B.a), x2 = ori(A.a, A.b, B.b);
        if(!x1 || !x2) {
            if(!x1) {
                return min(A.a.x, A.b.x) <= B.a.x && B.a.x <= max(A.a.x, A.b.x)
                    && min(A.a.y, A.b.y) <= B.a.y && B.a.y <= max(A.a.y, A.b.y);
            } else {
                return min(A.a.x, A.b.x) <= B.b.x && B.b.x <= max(A.a.x, A.b.x)
                    && min(A.a.y, A.b.y) <= B.b.y && B.b.y <= max(A.a.y, A.b.y);
            }
        }
        if(x1 * x2 != -1) return false;

        // cerr << x1 << " " << x2 << endl;

        x1 = ori(B.a, B.b, A.a), x2 = ori(B.a, B.b, A.b);

        if(!x1 || !x2) {
            if(!x1) {
                return min(B.a.x, B.b.x) <= A.a.x && A.a.x <= max(B.a.x, B.b.x)
                    && min(B.a.y, B.b.y) <= A.a.y && A.a.y <= max(B.a.y, B.b.y);
            } else {
                return min(B.a.x, B.b.x) <= A.b.x && A.b.x <= max(B.a.x, B.b.x)
                    && min(B.a.y, B.b.y) <= A.b.y && A.b.y <= max(B.a.y, B.b.y);
            }
        }
        
        return x1 * x2 == -1;
    };

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) if(intersect(v[i], v[j])) {
            join(i, j);
        }
    }

    while(m--) {
        int x, y; cin >> x >> y;
        --x, --y;
        cout << (same(x, y) ? "YES" : "NO") << endl;
    }
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