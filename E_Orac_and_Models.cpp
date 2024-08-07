#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1), dp(n + 1);
    for(int i = 1; i <= n; i++) {cin>>v[i]; dp[i] = 1; }

    for(int i = 1; i <= n; i++) {
        for(int j = 2 * i; j <= n; j += i) {
            if(v[j] > v[i]) dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    int ans = *max_element(dp.begin(), dp.end());
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