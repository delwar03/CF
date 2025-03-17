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

int n, q; 
vector<int> seg(4 * N);

#define lc (id << 1)
#define rc (id << 1 | 1)

void pull(int id) {
    seg[id] = __gcd(seg[lc], seg[rc]);
}

int merge(int a, int b) {
    return __gcd(a, b);
}

void upd(int id, int lo, int hi, int i, int x) {
    if(lo == hi) {
        seg[id] = x;
    } else {
        int mid = (lo + hi) >> 1;
        if(i <= mid) {
            upd(lc, lo, mid, i, x);
        } else {
            upd(rc, mid + 1, hi, i, x);
        }
        pull(id);
    }
}

int qur(int id, int lo, int hi, int l, int r) {
    if(l > hi || r < lo) return 0LL;
    if(l <= lo && hi <= r) return seg[id];
    int mid = (lo + hi) >> 1;
    return merge(qur(lc, lo, mid, l, r), qur(rc, mid + 1, hi, l, r));
}

void upd(int i, int x) {
    upd(1, 1, n, i, x);
}

int qur(int l, int r) {
    return qur(1, 1, n, l, r);
}

void solve() {
    cin>>n>>q;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        upd(i, abs(v[i] - v[i - 1]));
    }

    // for(int i = 1; i <= n; i++) cerr<<qur(i, i)<<" "; cerr<<endl;

    while(q--) {
        int l, r; cin>>l>>r;
        cout<<(l == r ? 0 : qur(l + 1, r))<<" \n"[q == 0];
    }
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