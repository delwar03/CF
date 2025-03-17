#include <bits/stdc++.h>
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

class SGTree {

public:
    vector<int> seg;
    
    SGTree() {}
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int> &a) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r, int x) {

        if(seg[ind] < x) return -1LL;
        if(low == high) return low;

        int mid = low + (high - low) / 2;
        if(seg[2 * ind + 1] >= x) return query(2 * ind + 1, low, mid, l, r, x);
        else return query(2 * ind + 2, mid + 1, high, l, r, x);
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] += val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    SGTree seg(n);
    seg.build(0, 0, n - 1, v);

    while(q--) {
        int x; cin>>x;
        int id = seg.query(0, 0, n - 1, 0, n - 1, x);
        if(~id) seg.update(0, 0, n - 1, id, -x);
        cout<<id + 1<<" \n"[q == 0];
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