#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

class SGTree {

public:
    vector<int> seg, lazy;
    
    SGTree(int n) {
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

        // When returning from funcion call update SegTree
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int l, int r, int val) {

        // Upadate the previous remaining updates
        // and propagate downwards
        if(lazy[ind] != 0) {
            seg[ind] += lazy[ind];
            // Propagaate the lazy updates downward
            // for the remainng nodes to be updated
            if(high != low) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // No overlap [l r low high] or [low high l r]
        if(l > high || r < low) return;

        // Complete overlap [l low high r]
        if(l <= low && r >= high) {
            seg[ind] += val;

            // If children exixts
            if(high != low) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        // Partial overlap
        int mid = low + (high - low) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }


    int query(int ind, int low, int high, int l, int r) {

        // If Upadates is remaining
        // Upadate it!!!
        if(lazy[ind] != 0) {
            seg[ind] += lazy[ind];
            // If children exists propagate downwards
            if(high != low) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // No Overleap
        // [low high] [l r] or [l r] [low high]
        // Should not contribute in our Answer
        if(l > high || r < low) return 0;

        // Complete Overleap
        // [l low high r]
        else if(l <= low && r >= high) return seg[ind];

        // Partial Overleap
        // Go left + Go right
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

void solve() {
    string s; cin>>s;
    int n = s.size();
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') v[i] = 1;
    }
    SGTree sg(n);
    sg.build(0, 0, n - 1, v);

    int q; cin>>q;
    while(q--) {
        char ch; cin>>ch;
        if(ch == 'I') {
            int l, r; cin>>l>>r;
            l--; r--;
            sg.update(0, 0, n - 1, l, r, 1);
        } else {
            int idx; cin>>idx;
            idx--;
            int val = sg.query(0, 0, n - 1, 0, idx);
            if(idx > 0) val -= sg.query(0, 0, n - 1, 0, idx - 1);
            cout<<val % 2<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": "<<endl;;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 