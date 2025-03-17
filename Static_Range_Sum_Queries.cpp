#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int n, q;
vector<int> v;

#define lc (id << 1)
#define rc (id << 1 | 1)

struct Node {
    int sm, lz;
    Node() : sm(0), lz(0) {}
    Node(int a) : sm(a), lz(0) {}
};

vector<Node> Seg(4 * N);

void push(int id, int lo, int hi) {
    if(!Seg[id].lz) return;
    Seg[id].sm += Seg[id].lz * (hi - lo + 1);
    if(lo ^ hi) {
        Seg[lc].lz += Seg[id].lz;
        Seg[rc].lz += Seg[id].lz;
    }
    Seg[id].lz = 0;
}

void pull(int id) {
    Seg[id].sm = Seg[lc].sm + Seg[rc].sm;
}

Node merge(Node left, Node right) {
    Node ret;
    ret.sm = left.sm + right.sm;
    return ret;
}

void build(int id, int lo, int hi) {
    Seg[id].lz = 0;
    if(lo == hi) {
        Seg[id].sm = v[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    build(lc, lo, mid);
    build(rc, mid + 1, hi);
    pull(id);
}

void upd(int id, int lo, int hi, int l, int r, int x) {
    push(id, lo, hi);
    if(l > hi || r < lo) return;
    if(l <= lo && hi <= r) {
        Seg[id].lz += x;
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
    if(l <= lo && hi <= r) return Seg[id];

    int mid = (lo + hi) >> 1;
    auto left = qur(lc, lo, mid, l, r);
    auto right = qur(rc, mid + 1, hi, l, r);
    return merge(left, right);
}

void upd(int l, int r, int x) {
    upd(1, 1, n, l, r, x);
}

int qur(int l, int r) {
    auto ret = qur(1, 1, n, l, r);
    return ret.sm;
}

void solve() {
    cin>>n>>q;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    build(1, 1, n);

    while(q--) {
        int l, r; cin>>l>>r;
        cout<<qur(l, r)<<endl;
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/