#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int pf[n + 1][32] = {};

    for(int i = 0; i < n; i++) {
        for(int j = 31; j >= 0; j--) {
            pf[i + 1][j] = pf[i][j];
            if((v[i] >> j) & 1) {
                pf[i + 1][j]++;
            }
        }
    }

    auto bs = [&] (int x, int k) {
        int l = x, r = n, ans = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            int res = 0;
            for(int j = 31; j >= 0; j--) {
                if(pf[m][j] - pf[x - 1][j] == m - x + 1) {
                    res += (1LL << j);
                }
            }
            if(res >= k) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    };

    int q; cin>>q;
    while(q--) {
        int l, k; cin>>l>>k;
        cout<<bs(l, k)<<" ";
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}

/*
i/p: 
o/p: 
*/