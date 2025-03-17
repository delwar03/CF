#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
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

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {

        if(l > high || r < low) return INF;
        if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<pair<int, int>> que[n];
    for(int i = 0; i < q; i++) {
        int l, r; cin>>l>>r;
        --l; --r;
        que[l].push_back({r, i});
    }

    SGTree seg(n);
    vector<int> tmp(n, INF);
    seg.build(0, 0, n - 1, tmp);

    map<int, int> mp;
    vector<int> ans(q);

    for(int i = n - 1; i >= 0; i--) {
        if(mp.count(v[i])) {
            seg.update(0, 0, n - 1, mp[v[i]], mp[v[i]] - i);
        }
        mp[v[i]] = i;

        for(auto it : que[i]) {
            int ind = it.S, r = it.F, l = i;
            ans[ind] = seg.query(0, 0, n - 1, l, r);
        }
    }

    // for(int i = 0; i < n; i++) cerr<<seg.query(0, 0, n - 1, i, i)<<" ";

    for(int i = 0; i < q; i++) {
        cout<<(ans[i] == INF ? -1 : ans[i])<<endl;
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