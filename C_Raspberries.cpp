#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    int even = 0;
    for(auto &x : v) {
        cin>>x;
        if(x % 2 == 0) even++;
        x %= k;
    }
    int ans = k;
    for(int i = 0; i < n; i++) {
        if(v[i] == 0) {
            ans = 0;
            break;
        }
        ans = min(ans, k - v[i]);
    }
    if(k == 4) {
        if(even >= 2) {
            ans = min(ans, 0LL);
        } else if(even == 1 && n > 1) {
            ans = min(ans, 1LL);
        } else {
            if(n > 1) {
                ans = min(ans, 2LL);
            } else {
                ans = min(ans, k - v[0]);
            }
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