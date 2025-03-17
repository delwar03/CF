#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
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
    int n; cin>>n;
    vector<Point> cord(n + 1);
    for(int i = 1; i <= n; i++) cin>>cord[i].x>>cord[i].y;
    vector<int> C(n + 1), K(n + 1);
    for(int i = 1; i <= n; i++) cin>>C[i];
    for(int i = 1; i <= n; i++) cin>>K[i];

    vector<array<int, 3>> edges;
    for(int i = 1; i <= n; i++) edges.push_back({C[i], 0, i});
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) edges.push_back({(K[i] + K[j]) * (abs(cord[i].x - cord[j].x) + abs(cord[i].y - cord[j].y)) , i, j});

    sort(edges.begin(), edges.end());

    vector<int> par(n + 5), siz(n + 5, 1);
    iota(par.begin(), par.end(), 0LL);

    function<int(int)> find = [&] (int u) {
        return (par[u] == u ? u : par[u] = find(par[u]));
    };

    auto join = [&] (int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        return true;
    };

    vector<pii> mst;
    int cost = 0;

    for(auto [c, u, v] : edges) {
        if(join(u, v)) {
            mst.push_back({u, v});
            cost += c;
        }
    }

    vector<int> grid;
    vector<pii> conn;

    for(auto [u, v] : mst) {
        if(u == 0 || v == 0) {
            grid.push_back(max(u, v));
        } else {
            conn.push_back({u, v});
        } 
    }

    for(auto &[u, v] : conn) if(u > v) swap(u, v);
    sort(grid.begin(), grid.end());
    sort(conn.begin(), conn.end());

    cout<<cost<<endl;
    cout<<sz(grid)<<endl;
    for(auto i : grid) cout<<i<<" "; cout<<endl;
    cout<<sz(conn)<<endl;
    for(auto [u, v] : conn) cout<<u<<" "<<v<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}