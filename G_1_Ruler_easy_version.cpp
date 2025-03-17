#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int l = 1, r = 1000;
    int ans = 2;
    while(l <= r) {
        int m = (r + l) / 2;
        cout<<"? "<<m<<" "<<m<<endl;
        int res;
        cin>>res;
        if(res == m * m) {
            l = m + 1;
        } else {
            ans = m;
            r = m - 1;
        }
    }
    cout<<"! "<<ans<<endl;
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