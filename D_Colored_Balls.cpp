#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(auto &x : v) {cin>>x; sum += x;}

    sort(v.begin(), v.end());

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    dp[0][0] = 1;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int sm = 0; sm <= sum; sm++) {
            int cur = v[i - 1];
            dp[i][sm] += dp[i - 1][sm];
            dp[i][sm] %= mod;
            if(sm + cur <= sum) {
                dp[i][sm + cur] += dp[i - 1][sm];
                dp[i][sm + cur] %= mod;
                int box = max((sm + cur + 1) / 2, cur);
                ans += box * dp[i][sm + cur];
                ans %= mod;
            }
        }
    }

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