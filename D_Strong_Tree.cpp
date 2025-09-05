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
const int INF = 1e12 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int mx, lz;
    Node() : mx(0), lz(0) {}
    Node(int a, int b) : mx(a), lz(b) {}
};

int n;
Node Seg[4 * N];

#define lc (id << 1)
#define rc (id << 1 | 1)

void push(int id, int lo, int hi) {
    if(!Seg[id].lz) return;
    Seg[id].mx += Seg[id].lz;
    if(lo ^ hi) Seg[lc].lz += Seg[id].lz, Seg[rc].lz += Seg[id].lz;
    Seg[id].lz = 0;
}

void pull(int id) {
    Seg[id].mx = max(Seg[lc].mx, Seg[rc].mx);
}

Node max(Node L, Node R) {
    Node ret;
    ret.mx = max(L.mx, R.mx);
    return ret;
}

void upd(int id, int lo, int hi, int l, int r, int x) {
    push(id, lo, hi);
    if(l > hi || r < lo) return;
    if(l <= lo && hi <= r) {Seg[id].lz += x, push(id, lo, hi); return;}
    int mid = (lo + hi) >> 1;
    upd(lc, lo, mid, l, r, x);
    upd(rc, mid + 1, hi, l, r, x);
    pull(id);
}

Node qur(int id, int lo, int hi, int l, int r) {
    push(id, lo, hi);
    if(l > hi || r < lo) return Node(-INF * N, 0);
    if(l <= lo && hi <= r) return Seg[id];
    int mid = lo + hi >> 1;
    return max(qur(lc, lo, mid, l, r), qur(rc, mid + 1, hi, l, r));
}

void upd(int l, int r, int x) {
    upd(1, 1, n, l, r, x);
}

int qur(int l, int r) {
    return qur(1, 1, n, l, r).mx;
}

void solve() {
    cin>>n;
    vector<int> g[n + 1], par(n + 1), val(n + 1), rnk(n + 1);
    for(int i = 2; i <= n; i++) cin>>par[i], g[par[i]].push_back(i);
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 1; i <= n; i++) cin>>rnk[i];

    vector<int> st(n + 1), en(n + 1), dep(n + 1);
    int tt = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        st[u] = ++tt;
        for(int v : g[u]) if(v ^ p) dep[v] = 1 + dep[u], dfs(v, u);
        en[u] = tt;
    };

    dfs(1, 0);

    vector<int> ans(n + 1), ord(n);
    iota(ord.begin(), ord.end(), 1LL);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
        return rnk[i] < rnk[j];
    });

    for(int i = 1; i <= n; i++) upd(st[i], en[i], -INF);

    for(int u : ord) {
        upd(st[u], en[u], INF + val[u]);
        vector<int> tmp;
        int prv = qur(st[u], st[u]);
        for(int v : g[u]) {
            int cur = qur(st[v], en[v]) - prv;
            if(cur > 0) tmp.push_back(cur);
        }
        sort(tmp.begin(), tmp.end());
        ans[u] = val[u];
        if(sz(tmp)) ans[u] += tmp.back(), tmp.pop_back();
        if(sz(tmp)) ans[u] += tmp.back(), tmp.pop_back();
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<" \n"[i == n];
    for(int i = 0; i < 4 * n; i++) Seg[i] = Node();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}