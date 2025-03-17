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

class lazySeg {

public:
    vector<int> seg, lazy;
    int n;
    
    lazySeg(int n) : n(n) {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int> &a) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int l, int r, int val) {

        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(high != low) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(l > high || r < low) return;

        if(l <= low && r >= high) {
            seg[ind] += val;
            if(high != low) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        int mid = low + (high - low) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }


    int query(int ind, int low, int high, int l, int r) {
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(high != low) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(l > high || r < low) return 0;
        else if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void upd(int l, int r, int x) {
        update(0, 0, n - 1, l, r, x);
    }

    int qur(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};


void solve() {
    int n, m; cin>>n>>m;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    lazySeg seg(n);
    seg.build(0, 0, n - 1, v);

    while(m--) {
        int ind; cin>>ind;
        int cur = seg.qur(ind, ind);
        seg.upd(ind, ind, 0 - cur);
        if(cur / n > 0)
            seg.upd(0, n - 1, cur / n);
        cur %= n;
        if(cur) {
            if(ind + cur < n) {
                seg.upd(ind + 1, ind + cur, +1);
            } else {
                seg.upd(ind + 1, n - 1, +1);
                cur -= (n - ind - 1);
                seg.upd(0, cur - 1, +1);
            }
        }
        // cerr<<"Seg: ";
        // for(int i = 0; i < n; i++) cerr<<seg.qur(i, i)<<" "; cerr<<endl;
    }

    for(int i = 0; i < n; i++) cout<<seg.qur(i, i)<<" ";
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