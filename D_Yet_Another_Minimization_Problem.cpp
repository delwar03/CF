#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n + 1), b(n + 1);
    int ans = 0, sum = 0;
    for(int i = 1; i <= n; i++) { cin>>a[i]; ans += a[i] * a[i]; sum += a[i]; }
    for(int i = 1; i <= n; i++) { cin>>b[i]; ans += b[i] * b[i]; sum += b[i]; }
    ans *= (n - 2);

    // Knapsack DP
    vector<vector<int>> dp(2, vector<int>(10005, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 10000; j++) {
            dp[i % 2][j] = 0;
            if(j - a[i] >= 0 && dp[(i - 1) % 2][j - a[i]]) dp[i % 2][j] = 1;
            if(j - b[i] >= 0 && dp[(i - 1) % 2][j - b[i]]) dp[i % 2][j] = 1;
        }
    }
    int sm1, sm2, mn = INF;
    for(int i = 0; i <= 10000; i++) {
        if(dp[n % 2][i]) {
            sm1 = i;
            sm2 = sum - i;
            int val = sm1 * sm1 + sm2 * sm2;
            if(val < mn) mn = val;
        }
    }
    ans += mn;
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