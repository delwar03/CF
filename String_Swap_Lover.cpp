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

struct lazySeg {

public:
    #define lc (id << 1)
    #define rc (id << 1 | 1)
    struct Node {
        int sm, lz;
    };
    vector<Node> seg;
    int n;

    lazySeg() {}
    lazySeg(int n) : n(n) {
        seg.resize(4 * n + 5);
    }
    
    void push(int id, int lo, int hi) {
        if(!seg[id].lz) return;
        seg[id].sm += (hi - lo + 1) * seg[id].lz;
        if(lo ^ hi) seg[lc].lz += seg[id].lz, seg[rc].lz += seg[id].lz;
        seg[id].lz = 0;
    }
    
    void pull(int id) {
        seg[id].sm = seg[lc].sm + seg[rc].sm;
    }
    
    Node mrg(Node a, Node b) {
        Node ret;
        ret.sm = a.sm + b.sm;
        return ret;
    }
    
    void upd(int id, int lo, int hi, int l, int r, int x) {
        push(id, lo, hi);
        if(l > hi || r < lo) return;
        if(l <= lo && hi <= r) {seg[id].lz += x, push(id, lo, hi); return;}
        int mid = (lo + hi) >> 1;
        upd(lc, lo, mid, l, r, x);
        upd(rc, mid + 1, hi, l, r, x);
        pull(id);
    }

    void tog(int id, int lo, int hi, int l, int r) {
        push(id, lo, hi);
        if(l > hi || r < lo) return;
        if(l <= lo && hi <= r) {seg[id].lz ^= 1, push(id, lo, hi); return;}
        int mid = (lo + hi) >> 1;
        upd(lc, lo, mid, l, r);
        upd(rc, mid + 1, hi, l, r);
        pull(id);
    }
    
    Node qry(int id, int lo, int hi, int l, int r) {
        push(id, lo, hi);
        if(l > hi || r < lo) return Node();
        if(l <= lo && hi <= r) return seg[id];
        int mid = (lo + hi) >> 1;
        return mrg(qry(lc, lo, mid, l, r), qry(rc, mid + 1, hi, l, r));
    }

    void tog(int l, int r) {
        tog(1, 1, n, l, r);
    }
    
    void upd(int l, int r, int x) {
        upd(1, 1, n, l, r, x);
    }
    
    int qry(int l, int r) {
        return qry(1, 1, n, l, r).sm;
    }
};

void solve() {
    int n; string s; cin >> n >> s;
    int cnt = count(s.begin(), s.end(), '1');
    
    lazySeg cnt(n);
    for(int i = 0; i < n; i++) cnt.upd(i, i, s[i] - '0');

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        cnt.tog(l, r);

        cerr << cnt.qry(1, n) << endl;

        
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}