#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        pos[x] = i;
    }
    int base = 1;
    while(base <= 2 * n) {
        base <<= 1;
    }
    vector<int> seg_mn(2 * base + 1), seg_mx(2 * base + 1);
    auto build = [&] {
        for(int i = 0; i <= n; i++) {
            seg_mx[i + n] = seg_mn[i + n] = pos[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            seg_mn[i] = min(seg_mn[2 * i], seg_mn[2 * i + 1]);
            seg_mx[i] = max(seg_mx[2 * i], seg_mx[2 * i + 1]);
        }
    };

    auto query = [&] (int l, int r, int mn) {
        l += n;
        r += n;
        int res;
        if(mn) {
            res = INF;
            while(l <= r) {
                if(l & 1) {
                    res = min(res, seg_mn[l++]);
                }
                if(!(r & 1)) {
                    res = min(res, seg_mn[r--]);
                }
                l >>= 1;
                r >>= 1;
            }
        } else {
            res = 0;
            while(l <= r) {
                if(l & 1) {
                    res = max(res, seg_mx[l++]);
                }
                if(!(r & 1)) {
                    res = max(res, seg_mx[r--]);
                }
                l >>= 1;
                r >>= 1;
            }
        }
        return res;
    };

    build();

    for(int k = n - 1; k >= 1; k--) {
        int l = query(n - k + 1, n, 1);
        int r = query(n - k + 1, n, 0);
        if(r - l + 1 == k) {
            cout<<k<<endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/