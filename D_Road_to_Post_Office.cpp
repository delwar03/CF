#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int d, k, a, b, t; cin>>d>>k>>a>>b>>t;
    if(k * a + t < k * b) {
        int ans = (d <= k ? d * a : k * a);
        d -= k;
        if(d <= 0) {
            cout<<ans<<endl;
        } else {
            int x = d / k;
            ans += x * (k * a + t);
            x = d % k;
            ans += min(x * b, x * a + t);
            cout<<ans<<endl;
        }
    } else {
        int ans = (d <= k ? d * a : k * a);
        d -= k;
        if(d <= 0) {
            cout<<ans<<endl;
        } else {
            ans += d * b;
            cout<<ans<<endl;
        }
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