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

struct DSU {
    vector<int> par, siz;
    DSU(int n) {
        siz = vector<int>(n + 1, 1);
        par = vector<int>(n + 1, 0);
        iota(par.begin(), par.end(), 0LL);
    }

    int find(int u) {
        return (par[u] == u ? u : par[u] = find(par[u]));
    }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return false;
        if(siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
};

void solve() {
    int n, m; cin>>n>>m;
    vector<array<int, 3>> edges(m);
    for(auto &[u, v, w] : edges) cin>>u>>v>>w;

    auto f = [&] (int mask) {
        DSU ds(n);
        for(auto [u, v, w] : edges) if((w & mask) == w) ds.join(u, v);
        return ds.same(1, n);
    };

    int ans = (1LL << 31) - 1;
    for(int i = 30; i >= 0; i--) {
        if(f(ans ^ (1LL << i))) ans ^= (1LL << i);
    }
    cout<<ans<<endl;
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