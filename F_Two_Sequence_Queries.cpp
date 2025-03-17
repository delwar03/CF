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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// (ai + x) * (bi + y) = ai*bi + ai*y + bi*x + x * y

struct Node {
    int sm[2], lz[2], mul;
};

int n, q;
int a[N], b[N];
vector<Node> Seg(4 * N);

#define lc (id << 1)
#define rc (id << 1 | 1)

void pull(int id) {
    Seg[id].sm[0] = (Seg[lc].sm[0] + Seg[rc].sm[0]) % mod;
    Seg[id].sm[1] = (Seg[lc].sm[1] + Seg[rc].sm[1]) % mod;
    Seg[id].mul = (Seg[lc].mul + Seg[rc].mul) % mod;
}

void push(int id, int lo, int hi) {
    if (!Seg[id].lz[0] && !Seg[id].lz[1]) return;
    Seg[id].mul += (((__int128) Seg[id].sm[0] * Seg[id].lz[1]) % mod + ((__int128) Seg[id].sm[1] * Seg[id].lz[0]) % mod + ((((__int128) Seg[id].lz[0] * Seg[id].lz[1]) % mod) * (hi - lo + 1)) % mod) % mod;
    Seg[id].mul %= mod;
    Seg[id].sm[0] += ((__int128) Seg[id].lz[0] * (hi - lo + 1)) % mod;
    Seg[id].sm[0] %= mod;
    Seg[id].sm[1] += ((__int128) Seg[id].lz[1] * (hi - lo + 1)) % mod;
    Seg[id].sm[1] %= mod;
    if(lo ^ hi) {
        Seg[lc].lz[0] += Seg[id].lz[0];
        Seg[lc].lz[0] %= mod;
        Seg[lc].lz[1] += Seg[id].lz[1];
        Seg[lc].lz[1] %= mod;
        Seg[rc].lz[0] += Seg[id].lz[0];
        Seg[rc].lz[0] %= mod;
        Seg[rc].lz[1] += Seg[id].lz[1];
        Seg[rc].lz[1] %= mod;
    }
    Seg[id].lz[0] = Seg[id].lz[1] = 0;
}

Node merge(Node left, Node right) {
    Node ret;
    ret.sm[0] = (left.sm[0] + right.sm[0]) % mod;
    ret.sm[1] = (left.sm[1] + right.sm[1]) % mod;
    ret.mul = (left.mul + right.mul) % mod;
    return ret;
}

void build(int id, int lo, int hi) {
    if(lo == hi) {
        Seg[id].sm[0] = a[lo];
        Seg[id].sm[1] = b[lo];
        Seg[id].mul = (a[lo] * b[lo]) % mod;
    } else {
        int mid = (lo + hi) >> 1;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        pull(id);
    }
}

void upd(int id, int lo, int hi, int l, int r, int x, int f) {
    push(id, lo, hi);
    if(l > hi || r < lo) return;
    if(l <= lo && hi <= r) {
        Seg[id].lz[f] += x;
        push(id, lo, hi);
        return;
    }
    int mid = (lo + hi) >> 1;
    upd(lc, lo, mid, l, r, x, f);
    upd(rc, mid + 1, hi, l, r, x, f);
    pull(id);
}

Node qur(int id, int lo, int hi, int l, int r) {
    push(id, lo, hi);
    if(l > hi || r < lo) return Node();
    if(l <= lo && hi <= r) return Seg[id];
    int mid = (lo + hi) >> 1;
    return merge(qur(lc, lo, mid, l, r), qur(rc, mid + 1, hi, l, r));
}

void upd(int l, int r, int x, int f) {
    upd(1, 1, n, l, r, x, f);
}

int qur(int l, int r) {
    return qur(1, 1, n, l, r).mul;
}

void solve() {
    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>b[i];

    build(1, 1, n);

    while(q--) {
        int typ; cin>>typ;
        if(typ == 1 || typ == 2) {
            int l, r, x; cin>>l>>r>>x;
            upd(l, r, x, (typ == 1 ? 0 : 1));
        } else if(typ == 3) {
            int l, r; cin>>l>>r;
            cout<<qur(l, r)<<endl;
        } else {
            assert(false);
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