#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void add_div(int x, map<int, int>& mp) {
    int i = 2;
    while(i * i <= x) {
        while(x % i == 0) {
            mp[i]++;
            x /= i;
        }
        i++;
    }
    if(x > 1) mp[x]++;
}

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> dp(n + 1, n);
    dp[n] = 0;
    for(int i = n - 1;  i >= 0; i--) {
        dp[i] = dp[i + 1] + 1;
        if(i + v[i] < n) dp[i] = min(dp[i], dp[i + v[i] + 1]);
    }
    cout<<dp[0]<<endl;
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