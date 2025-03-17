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
const int N = 4e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int orr, lz;
    Node() : orr(0), lz(0) {}
    Node(int a, int b) : orr(a), lz(b) {}
};

#define lc (id << 1)
#define rc (id << 1 | 1)

int n, m;
vector<Node> seg(4 * N);

void pull(int id) {
    seg[id].orr = seg[lc].orr | seg[rc].orr;
}

Node merge(Node left, Node right) {
    Node ret;
    ret.orr = left.orr | right.orr;
    return ret;
}

void push(int id, int lo, int hi) {
    if(seg[id].lz) {
        seg[id].orr = seg[id].lz;
        if(lo ^ hi) {
            seg[lc].lz = seg[id].lz;
            seg[rc].lz = seg[id].lz;
        }
        seg[id].lz = 0;
    }
}

void upd(int id, int lo, int hi, int l, int r, int x) {
    push(id, lo, hi);
    if(l > hi || r < lo) return;
    if(l <= lo && hi <= r) {
        seg[id].lz = x;
        push(id, lo, hi);
        return;
    }
    int mid = (lo + hi) >> 1;
    upd(lc, lo, mid, l, r, x);
    upd(rc, mid + 1, hi, l, r, x);
    pull(id);
}

Node qur(int id, int lo, int hi, int l, int r) {
    push(id, lo, hi);
    if(l > hi || r < lo) return Node();
    if(l <= lo && hi <= r) return seg[id];
    
    int mid = (lo + hi) >> 1;
    return merge(qur(lc, lo, mid, l, r), qur(rc, mid + 1, hi, l, r));
}

void upd(int l, int r, int x) {
    upd(1, 1, n, l, r, x);
}

int qur(int l, int r) {
    return qur(1, 1, n, l, r).orr;
}

void solve() {
    cin>>n>>m;
    vector<int> g[n + 1], col(n + 1);
    for(int i = 1; i <= n; i++) cin>>col[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> st(n + 1), en(n + 1), par(n + 1), lt(2 * n + 1);
    int timer = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        st[u] = ++timer;
        for(auto v : g[u]) {
            if(v ^ p) {
                par[v] = u;
                dfs(v, u);
            }
        }
        en[u] = timer;
    };

    dfs(1, 0);
    
    for(int i = 1; i <= n; i++) upd(st[i], st[i], (1LL << col[i]));

    while(m--) {
        int typ; cin>>typ;
        if(typ == 1) {
            int u, c; cin>>u>>c;
            upd(st[u], en[u], (1LL << c));
        } else {
            int u; cin>>u;
            cout<<__builtin_popcountll(qur(st[u], en[u]))<<endl;
        }
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