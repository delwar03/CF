#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
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
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {

        // No Overleap
        // [low high] [l r] or [l r] [low high]
        // Should not contribute in our Answer
        if(l > high || r < low) return INT_MAX;

        // Complete Overleap
        // [l low high r]
        else if(l <= low && r >= high) return seg[ind];

        // Partial Overleap
        // Go left + Go right
        else {
            int mid = low + (high - low) / 2;
            int left = query(2 * ind + 1, low, mid, l, r);
            int right = query(2 * ind + 2, mid + 1, high, l, r);
            return min(left, right);
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
        
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    int ans = 0;
    for(auto &x : v) {cin>>x; mp[x]++;}
    for(int i = 0; i < n; i++) {
        if(v[i] <= 0) {
            int val = -v[i];
            int p = -1000, q = val + 1000;
            while(p <= q) {
                if(mp.count(p)) {
                    if(p == q) {
                        if(mp.count(p) && mp[p] >= 2) {
                            cout<<"YES"<<endl;
                            return;
                        }
                    } else {
                        if(mp.count(p) && mp.count(q)) {
                            cout<<"YES"<<endl;
                            return;
                        }
                    }
                }
                p++;
                q--;
            }
        }
    }
    cout<<"NO"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
