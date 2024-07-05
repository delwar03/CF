#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    int mx = k * (k + 1) / 2 - (k - 1);
    // cerr<<mx<<endl;

    if(n == 1) {cout<<0<<endl; return; }

    auto bs = [&] (int n) {
        int l = 2, r = k, ans = 2;
        while(l <= r) {
            int m = (l + r) / 2;
            int sm = (k + m) * (k - m + 1) / 2;
            sm -= (k - m);
            if(sm >= n) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        // cerr<<ans<<endl;
        return (k - ans + 1);
    };

    if(n > mx) {
        cout<<-1<<endl;
    } else {
        cout<<bs(n)<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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