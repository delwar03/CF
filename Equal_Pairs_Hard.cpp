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

        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {

        if(l > high || r < low) return 0;
        if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return (left + right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }
};

void solve() {
    int n; cin>>n;
    vector<int> freq(n), val(n);
    SGTree seg(n);
    seg.build(0, 0, n - 1, val);
    int z = n, mx = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        --y;
        freq[y]++;
        z--;
        val[y] = freq[y] * (freq[y] - 1) / 2;
        seg.update(0, 0, n - 1, y, val[y]);

        int ans = seg.query(0, 0, n - 1, 0, n - 1);

        mx = max(mx, freq[y]);

        ans -= mx * (mx - 1) / 2;
        ans += (mx + z) * (mx + z - 1) / 2;

        cout<<ans<<" \n"[i == n - 1];
    }
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