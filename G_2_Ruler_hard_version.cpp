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
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        cout<<"? "<<m1<<" "<<m2<<endl;
        int res;
        cin>>res;
        if(res == m1 * m2) {
            l = m2 + 1;
        } else if(res == m1 * (m2 + 1)) {
            ans = m2;
            l = m1 + 1;
            r = m2 - 1;
        } else {
            ans = m1;
            r = m1 - 1;
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