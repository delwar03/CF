#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    string s; cin>>s;
    int n = s.size();
    int dp[n + 1][2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = s[0] != '1';
    dp[0][1] = s[0] != '0';
    for(int i = 1; i < n; i++) {
        if(s[i] == '?') {
            dp[i][0] = 1 + dp[i - 1][1];
            dp[i][1] = 1 + dp[i - 1][0];
        } else if(s[i] == '0') {
            dp[i][0] = 1 + dp[i - 1][1];
        } else {
            dp[i][1] = 1 + dp[i - 1][0];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(dp[i][0], dp[i][1]);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 