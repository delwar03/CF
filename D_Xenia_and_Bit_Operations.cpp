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

// even -> 1
// odd -> 0

// (n % 2 == 0)

#define lc (id << 1)
#define rc (id << 1 | 1)

struct Node {
    int val;
    Node() : val(0) {}
    Node(int v) : val(v) {}
};

int n, q;
vector<int> tmp;
vector<Node> Seg(4 * N);

void pull(int id, int f) {
    if(f) {
        Seg[id].val = (Seg[lc].val | Seg[rc].val);
    } else {
        Seg[id].val = (Seg[lc].val ^ Seg[rc].val);
    }
}

Node merge(Node left, Node right, int f) {
    Node ret;
    if(f) {
        ret.val = (left.val | right.val);
    } else {
        ret.val = (left.val ^ right.val);
    }
    return ret;
}

void build(int id, int lo, int hi, int f) {
    if(lo == hi) {
        Seg[id] = Node(tmp[lo]);
    } else {
        int mid = (lo + hi) >> 1;
        build(lc, lo, mid, !f);
        build(rc, mid + 1, hi, !f);
        pull(id, !f);
    }
}

void upd(int id, int lo, int hi, int i, int x, int f) {
    if(lo == hi) {
        Seg[id] = Node(x);
    } else {
        int mid = (lo + hi) >> 1;
        if(i <= mid)
            upd(lc, lo, mid, i, x, !f);
        else
            upd(rc, mid + 1, hi, i, x, !f);
        pull(id, !f);
    }
}

Node qur(int id, int lo, int hi, int l, int r, int f) {
    if(l > hi || r < lo) return Node();
    if(l <= lo && hi <= r) return Seg[id];
    int mid = (lo + hi) >> 1;
    auto left = qur(lc, lo, mid, l, r, !f);
    auto right = qur(rc, mid + 1, hi, l, r, !f);
    return merge(left, right, !f);
}

void upd(int i, int x, int f) {
    upd(1, 1, n, i, x, f);
}

int qur(int l, int r, int f) {
    return qur(1, 1, n, 1, n, f).val;
}

void solve() {
    cin>>n>>q;
    int f = (n % 2 == 0);
    n = (1LL << n);
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    tmp = v;

    build(1, 1, n, f);

    while(q--) {
        int i, x; cin>>i>>x;
        upd(i, x, f);
        v[i] = x;
        cout<<qur(1, n, f)<<endl;
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