#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int mn = INF, sum = 0;

void solve() {

    int k, x; cin>>k>>x;
    int l = 0, r = 2 * k - 1, ans = 2 * k - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        int tot = 0;
        if(mid <= k) {
            tot = mid * (mid + 1) / 2;
        } else {
            int extra = 2 * k - 1 - mid;
            tot = k * k - extra * (extra + 1) / 2;
        }
        if(tot >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 