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
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> tmp;

#define lc (id << 1)
#define rc (id << 1 | 1)

int SegGCD[4 * N];
pair<int, int> SegMn[4 * N]; // {mn, cnt}

void buildGCD(int id, int lo, int hi) {
    if(lo == hi) {
        SegGCD[id] = tmp[lo];
    } else {
        int mid = (lo + hi) >> 1;
        buildGCD(lc, lo, mid);
        buildGCD(rc, mid + 1, hi);
        SegGCD[id] = __gcd(SegGCD[lc], SegGCD[rc]);
    }
}

int qurGCD(int id, int lo, int hi, int l, int r) {
    if(l > hi || r < lo) return 0;
    if(l <= lo && hi <= r) return SegGCD[id];
    int mid = (lo + hi) >> 1;
    return __gcd(qurGCD(lc, lo, mid, l, r), qurGCD(rc, mid + 1, hi, l, r));
}

int qurGCD(int l, int r) {
    return qurGCD(1, 1, n, l, r);
}


void buildMn(int id, int lo, int hi) {
    if(lo == hi) {
        SegMn[id] = {tmp[lo], 1};
    } else {
        int mid = (lo + hi) >> 1;
        buildMn(lc, lo, mid);
        buildMn(rc, mid + 1, hi);
        if(SegMn[lc].F != SegMn[rc].F) {
            SegMn[id] = min(SegMn[lc], SegMn[rc]);
        } else {
            SegMn[id] = {SegMn[lc].F, SegMn[lc].S + SegMn[rc].S};
        }
    }
}

pair<int, int> qurMn(int id, int lo, int hi, int l, int r) {
    if(l > hi || r < lo) return {INF, 0};
    if(l <= lo && hi <= r) return SegMn[id];
    int mid = (lo + hi) >> 1;
    auto left = qurMn(lc, lo, mid, l, r);
    auto right = qurMn(rc, mid + 1, hi, l, r);
    if(left.F != right.F) {
        return min(left, right);
    } else {
        return {left.F, left.S + right.S};
    }
}

pair<int, int> qurMn(int l, int r) {
    return qurMn(1, 1, n, l, r);
}

void solve() {
    cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    tmp = v;
    buildGCD(1, 1, n);
    buildMn(1, 1, n);

    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        int sz = r - l + 1;
        int g = qurGCD(l, r);
        auto q = qurMn(l, r);

        // cerr<<g<<" "<<q.F<<" "<<q.S<<endl;

        int ans = sz;
        if(q.F == g) ans -= q.S;

        cout<<ans<<endl;
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