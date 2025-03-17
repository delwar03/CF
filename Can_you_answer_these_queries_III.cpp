#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q;
vector<int> tmp;

#define lc (id << 1)
#define rc (id << 1 | 1)

struct Node {
    int sum, pref, suff, mx;
    Node() : sum(0), pref(-INF), suff(-INF), mx(-INF) {}
    Node(int val) : sum(val), pref(val), suff(val), mx(val) {}
};

vector<Node> Seg(4 * N);

// [L....a..........p || R..........b...q]

void pull(int id) {
    Seg[id].sum = Seg[lc].sum + Seg[rc].sum;
    Seg[id].pref = max(Seg[lc].pref, Seg[lc].sum + Seg[rc].pref);
    Seg[id].suff = max(Seg[rc].suff, Seg[rc].sum + Seg[lc].suff);
    Seg[id].mx = max({Seg[lc].mx, Seg[rc].mx, Seg[lc].suff + Seg[rc].pref});
}

Node merge(Node left, Node right) {
    Node ret;
    ret.sum = left.sum + right.sum;
    ret.pref = max(left.pref, left.sum + right.pref);
    ret.suff = max(right.suff, right.sum + left.suff);
    ret.mx = max({left.mx, right.mx, left.suff + right.pref});
    return ret;
}

void build(int id, int lo, int hi) {
    if(lo == hi) {
        Seg[id] = Node(tmp[lo]);
        return;
    }
    int mid = (lo + hi) >> 1;
    build(lc, lo, mid);
    build(rc, mid + 1, hi);
    pull(id);
}

void upd(int id, int lo, int hi, int i, int x) {
    if(lo == hi) {
        Seg[id] = Node(x);
        return;
    }
    int mid = (lo + hi) >> 1;
    if(i <= mid)
        upd(lc, lo, mid, i, x);
    else
        upd(rc, mid + 1, hi, i, x);
    pull(id);
}

Node qur(int id, int lo, int hi, int l, int r) {
    if(l > hi || r < lo) return Node();
    if(l <= lo && hi <= r) return Seg[id];

    int mid = (lo + hi) >> 1;
    auto left = qur(lc, lo, mid, l, r);
    auto right = qur(rc, mid + 1, hi, l, r);
    return merge(left, right);
}

void upd(int i, int x) {
    upd(1, 1, n, i, x);
}

int qur(int l, int r) {
    auto ret = qur(1, 1, n, l, r);
    return ret.mx;
}


void solve() {
    cin>>n;
    vector<int> val(n + 1);
    for(int i = 1; i <= n; i++) cin>>val[i];

    tmp = val;

    build(1, 1, n);

    cin>>q;
    while(q--) {
        int ty; cin>>ty;
        if(ty == 0) {
            int i, x; cin>>i>>x;
            upd(i, x);
        } else {
            int l, r; cin>>l>>r;
            cout<<qur(l, r)<<endl;
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

/*
i/p: 
o/p: 
*/