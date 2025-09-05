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

class lazySeg {
    
    public:
    #define lc (id << 1)
    #define rc (id << 1 | 1)
    
    int n, m;
    vector<vector<int>> seg;

    lazySeg() {}
    lazySeg(int n, int m) : n(n), m(m) {
        seg.resize(4 * n + 5);
        for(auto &x : seg) x = vector<int>(m), x[0] = 1;
    }
    
    vector<int> mrg(const vector<int>& a, const vector<int>& b) {
        vector<int> ret(m);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                int t = i + j;
                if(t >= m) t -= m;
                (ret[t] += a[i] * b[j]) %= mod;
            }
        }
        return ret;
    }
    
    void upd(int id, int lo, int hi, int i, int x) {
        if(lo == hi) {
            (seg[id][x % m] += 1) %= mod;
            return;
        }
        int mid = (lo + hi) >> 1;
        if(i <= mid) upd(lc, lo, mid, i, x);
        else upd(rc, mid + 1, hi, i, x);
        seg[id] = mrg(seg[lc], seg[rc]);
    }
    
    vector<int> qry(int id, int lo, int hi, int l, int r) {
        if(l > hi || r < lo) {
            vector<int> tmp(m); tmp[0] = 1;
            return tmp;
        }
        if(l <= lo && hi <= r) return seg[id];
        int mid = (lo + hi) >> 1;
        return mrg(qry(lc, lo, mid, l, r), qry(rc, mid + 1, hi, l, r));
    }
    
    void upd(int i, int x) {
        upd(1, 1, n, i, x);
    }
    
    int qry(int l, int r) {
        return qry(1, 1, n, l, r)[0];
    }
};

void solve() {
    int n, m; cin>>n>>m;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    lazySeg st(n, m);
    for(int i = 1; i <= n; i++) st.upd(i, v[i]);

    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<st.qry(l, r)<<endl;
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