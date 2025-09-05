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

#define lc (id << 1)
#define rc (id << 1 | 1)

void solve() {
    int n, q; cin>>n>>q;
    vector<int> val(n), g[n];
    for(auto &x : val) cin>>x;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    o_set<int> Seg[2 * n + 10];
    vector<int> st(n), en(n);
    int tt = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        st[u] = ++tt;
        Seg[n + tt].insert(val[u]);
        for(auto v : g[u]) if(v ^ p) dfs(v, u);
        en[u] = tt;
    };

    dfs(0, -1);

    for(int i = n; i; i--) {
        for(int x : Seg[2 * i]) Seg[i].insert(x);
        for(int x : Seg[2 * i + 1]) Seg[i].insert(x);
    }
    
    auto qry = [&] (int l, int r, int x) {
        int ret = 0;
        for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) ret += Seg[l++].order_of_key(x);
            if(!(r & 1)) ret += Seg[r--].order_of_key(x);
        }
        return ret;
    };

    auto upd = [&] (int i, int x) {
        for(Seg[i += n].insert(x), i >>= 1; i; i >>= 1) Seg[i].insert(x);
    };

    while(q--) {
        int u, v; cin>>u>>v;
        cout<<qry(st[u], en[u], v)<<endl;
        upd(st[u], v);
    }
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