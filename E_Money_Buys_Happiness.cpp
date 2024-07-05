#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 60;
const int INF = 1e15 + 10;

int n, x;
int dp[N];
vector<int> c(N), h(N);

int calc(int i, int sum) {
    if(i == n) {
        return 0;
    }
    
    if(dp[i] != -1)
        return dp[i];
    
    int ans = calc(i + 1, sum + x);
    if(sum >= c[i]) ans = max(ans, h[i] + calc(i + 1, sum - c[i] + x));

    return dp[i] = ans;
}

void solve() {
    cin>>n>>x;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) cin>>c[i]>>h[i];

    calc(0, x);
    for(int i = 0; i <= n; i++)
        cout<<dp[i]<<" \n"[i == n];
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