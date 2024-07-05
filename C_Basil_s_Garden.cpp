#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    
    vector<int> dp(n + 1);

    for(int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i + 1] + 1, v[i]);
    }
    cout<<dp[0]<<endl;
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