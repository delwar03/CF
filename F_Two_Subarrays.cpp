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
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define lc (id << 1)
#define rc (id << 1 | 1)

int A[N], B[N];

struct Node {
    int sm, a2b;
    Node() : sm(0), a2b(-INF) {}
    Node(int a, int b) : sm(a), a2b(b) {}
};

vector<Node> seg(4 * N);

void pull(int id) {
    seg[id].sm = seg[lc].sm + seg[rc].sm;
    seg[id].a2b = max(seg[lc].a2b, seg[rc].a2b);
}

Node merge(Node a, Node b) {
    Node ret;
    ret.sm = a.sm + b.sm;
    ret.a2b = max(a.a2b, b.a2b);
    return ret;
}

void build(int id, int lo, int hi) {
    if(lo == hi) {
        seg[id].sm = A[lo];
        seg[id].a2b = A[lo] + 2 * B[lo];
    } else {
        int mid = (lo + hi) >> 1;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        pull(id);
    }
}

void upd(int id, int lo, int hi, int i, int x, int f) {
    if(lo == hi) {
        if(!f) {
            seg[id].sm = x;
            seg[id].a2b += x - A[i];
        } else {
            seg[id].a2b += 2 * (x - B[i]);
        }
    } else {
        int mid = (lo + hi) >> 1;
        if(i <= mid) {
            upd(lc, lo, mid, i, x, f);
        } else {
            upd(rc, mid + 1, hi, i, x, f);
        }
        pull(id);
    }
}

Node qur(int id, int lo, int hi, int l, int r) {
    if(l > hi || r < lo) return Node();
    if(l <= lo && hi <= r) return seg[id];
    int mid = (lo + hi) >> 1;
    return merge(qur(lc, lo, mid, l, r), qur(rc, mid + 1, hi, l, r));
}

void solve() {
    int n; cin>>n;
    for(int i = 0; i < n; i++) cin>>A[i];
    for(int i = 0; i < n; i++) cin>>B[i];

    build(1, 1, n);

    auto brute = [&] (int l, int r) {
        int ans = B[l] + B[r];
        for(int i = l; i <= r; i++) ans += A[i];
        int mx = -INF;
        for(int i = l; i < r; i++) mx = max(mx, B[i] + B[i + 1]);
        return ans + mx;
    };

    int q; cin>>q;
    while(q--) {
        int typ; cin>>typ;
        if(typ == 1) {
            int i, x; cin>>i>>x;
            --i;
            upd(1, 1, n, i, x, 0);
            A[i] = x;
        } else if(typ == 2) {
            int i, x; cin>>i>>x;
            --i;
            upd(1, 1, n, i, x, 1);
            B[i] = x;
        } else {
            int l, r; cin>>l>>r;
            --l; --r;
            auto res = qur(1, 1, n, l, r);
            int ans = res.sm + B[l] + B[r];
            ans += res.a2b;
            cout<<ans<<endl;
            cerr<<brute(l, r)<<endl;
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