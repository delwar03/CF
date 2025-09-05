#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
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

#define mat array<array<int, 2>, 2>
#define lc (id << 1)
#define rc (id << 1 | 1)

mat bse = {1, 1, 1, 0}, I = {1, 0, 0, 1}, Z = {0, 0, 0, 0};

struct Node {
    mat a, lz;
    Node() : a(I), lz(I) {}
    Node(int f) : a(Z), lz(I) {}
};

int n, q;
Node seg[4 * N];

mat matMult(const mat& a, const mat& b) {
    mat c {};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                (c[i][j] += (1LL * a[i][k] * b[k][j]) % mod) %= mod;
            }
        }
    }
    return c;
}

mat matAdd(const mat& a, const mat& b) {
    mat c {};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            (c[i][j] += (1LL * a[i][j] + b[i][j])) %= mod;
        }
    }
    return c;
}

mat matPow(mat a, int b) {
    mat ret = I;
    while(b > 0) {
        if(b & 1) ret = matMult(ret, a);
        a = matMult(a, a);
        b >>= 1;
    }
    return ret;
}

void push(int id, int lo, int hi) {
    if(seg[id].lz == I) return;
    seg[id].a = matMult(seg[id].a, seg[id].lz);
    if(lo ^ hi) seg[lc].lz = matMult(seg[lc].lz, seg[id].lz), seg[rc].lz = matMult(seg[rc].lz, seg[id].lz);
    seg[id].lz = I;
}

void pull(int id) {
    seg[id].a = matAdd(seg[lc].a, seg[rc].a);
}

Node merge(const Node& a, const Node& b) {
    Node ret;
    ret.a = matAdd(a.a, b.a);
    return ret;
}

void upd(int id, int lo, int hi, int l, int r, int x) {
    push(id, lo, hi);
    if(l > hi || r < lo) return;
    if(l <= lo && hi <= r) {seg[id].lz = matMult(seg[id].lz, matPow(bse, x)), push(id, lo, hi); return;}
    int mid = (lo + hi) >> 1;
    upd(lc, lo, mid, l, r, x);
    upd(rc, mid + 1, hi, l, r, x);
    pull(id);
}

Node qur(int id, int lo, int hi, int l, int r) {
    push(id, lo, hi);
    if(l > hi || r < lo) return Node(0);
    if(l <= lo && hi <= r) return seg[id];
    int mid = (lo + hi) >> 1;
    return merge(qur(lc, lo, mid, l, r), qur(rc, mid + 1, hi, l, r));
}

void upd(int l, int r, int x) {
    upd(1, 1, n, l, r, x);
}

int qur(int l, int r) {
    return qur(1, 1, n, l, r).a[0][1];
}

void solve() {
    cin>>n>>q;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    for(int i = 1; i <= n; i++) upd(i, i, v[i]);

    while(q--) {
        int typ; cin>>typ;
        if(typ == 1) {
            int l, r, x; cin>>l>>r>>x;
            upd(l, r, x);
        } else {
            int l, r; cin>>l>>r;
            cout<<qur(l, r)<<endl;
        }
    }
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