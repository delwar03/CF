#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class SGTree {

public:
    vector<int> seg;
    
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

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {

        if(l > high || r < low) return 0;
        if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

void solve() {
    int n, m; cin>>n>>m;
    vector<pair<int, int>> v;
    for(int i = 0; i < m; i++) {
        int l, r; cin>>l>>r;
        --l; --r;
        v.push_back({l, r});
    }

    int q; cin>>q;
    vector<int> query(q);
    for(auto &x : query) {cin>>x; --x;}

    auto f = [&] (int ind) {
        vector<int> tmp(n, 0);
        SGTree st(n);
        st.build(0, 0, n - 1, tmp);

        for(int i = 0; i <= ind; i++) {
            st.update(0, 0, n - 1, query[i], +1);
        }

        for(auto it : v) {
            int l = it.ff, r = it.ss;
            int sum = st.query(0, 0, n - 1, l, r);
            if(2 * sum > (r - l + 1)) return true;
        }
        return false;
    };

    int l = 0, r = q - 1, best = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(f(mid)) {
            best = mid + 1;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout<<best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/