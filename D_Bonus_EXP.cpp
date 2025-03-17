#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    vector<vector<int>> dp(n + 1, vector<int>(2, -INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + v[i]);
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 2 * v[i]);
    }

    int ans = max(dp[n][0], dp[n][1]);
    cout<<ans<<endl;
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