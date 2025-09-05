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

class lazySeg {

public:
    #define lc (id << 1)
    #define rc (id << 1 | 1)
    struct Node {
        int sm, lz;
        Node() : sm(0), lz(0) {}
        Node(int a) : sm(a), lz(0) {}
    };
    vector<Node> seg;
    int n;

    lazySeg() {}
    lazySeg(int n) : n(n) {
        seg.resize(4 * n + 5);
    }
    
    void push(int id, int lo, int hi) {
        if(!seg[id].lz) return;
        seg[id].sm += seg[id].lz;
        if(lo ^ hi) seg[lc].lz += seg[id].lz, seg[rc].lz += seg[id].lz;
        seg[id].lz = 0;
    }
    
    void pull(int id) {
        seg[id].sm = min(seg[lc].sm, seg[rc].sm);
    }
    
    Node mrg(Node a, Node b) {
        Node ret;
        ret.sm = min(a.sm, b.sm);
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
    
    Node qry(int id, int lo, int hi, int l, int r) {
        push(id, lo, hi);
        if(l > hi || r < lo) return Node(INF);
        if(l <= lo && hi <= r) return seg[id];
        int mid = (lo + hi) >> 1;
        return mrg(qry(lc, lo, mid, l, r), qry(rc, mid + 1, hi, l, r));
    }
    
    void upd(int l, int r, int x) {
        upd(1, 1, n, l, r, x);
    }
    
    int qry(int l, int r) {
        return qry(1, 1, n, l, r).sm;
    }
};

void solve() {
    int n; cin>>n;
    lazySeg seg(n + 10);
    for(int i = 0, x; i < n; i++) cin>>x, seg.upd(x + 1, x + 1, +1);

    // for(int i = 1; i <= n; i++) cerr<<seg.qry(i, i)<<" "; cerr<<endl;

    vector<int> v;
    while(seg.qry(1, 1)) {
        int lo = 1, hi = n + 1, best = -1;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(seg.qry(0, mid) > 0) best = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        v.push_back(best);
        seg.upd(0, best, -1);
    }

    int sm = 0;
    for(int i = 1; i <= n + 1; i++) sm += seg.qry(i, i);
    for(int i = 0; i < sm; i++) v.push_back(0);

    cout<<sz(v)<<endl;
    for(int i = 0; i < sz(v); i++) cout<<v[i]<<" \n"[i == sz(v) - 1];
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