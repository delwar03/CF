#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

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

        // When returning from funcion call update SegTree
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {

        // No Overleap
        // [low high] [l r] or [l r] [low high]
        // Should not contribute in our Answer
        if(l > high || r < low) return 0;

        // Complete Overleap
        // [l low high r]
        else if(l <= low && r >= high) return seg[ind];

        // Partial Overleap
        // Go left + Go right
        else {
            int mid = low + (high - low) / 2;
            int left = query(2 * ind + 1, low, mid, l, r);
            int right = query(2 * ind + 2, mid + 1, high, l, r);
            return max(left, right);
        }
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

void solve() {
    string s; cin>>s;
    int n = s.size();
    vector<int> pf(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pf[i + 1] = s[i] == '(' ? 1 : -1;
    }
    for(int i = 1; i <= n; i++) {
        pf[i] += pf[i - 1];
    }
    SGTree seg(n);
    seg.build(0, 0, n, pf);
    map<int, vector<int>> mp;
    int ans = 0;
    // for(int i = 0; i <= n; i++) cerr<<pf[i]<<" "; cerr<<endl;

    for(int i = 0; i <= n; i++) {
        if(pf[i]) {
            mp[pf[i]].push_back(i);
        }
    }
    for(auto it : mp) {
        int val = it.first;
        auto vec = it.second;
        int sz = vec.size();
        int cnt = 1, prv = vec[0];
        for(int i = 1; i < sz; i++) {
            int mx = seg.query(0, 0, n, prv, vec[i]);
            if(mx > 2 * val) {
                cnt = 1;
                prv = vec[i];
            } else {
                ans += cnt++;
            }
        }
    }
    cout<<ans<<endl;
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