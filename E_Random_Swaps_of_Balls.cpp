#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[N][2]; 
// dp[i][1] -> probability of the black ball being on 1st index after the i'th step
// dp[i][0] -> probability of the black ball being on other than 1st index after the i'th step

void solve() {
    int n, k; cin>>n>>k;

    function<int(int)> inv = [&] (int n) {
        if(n <= 1) return n;
        return mod - (mod / n) * inv(mod % n) % mod;
    };

    dp[0][1] = 1;
    dp[0][0] = 0;

    int d = inv((n * (__int128) n) % mod);

    for(int i = 1; i <= k; i++) {
        dp[i][1] = ((((1 + ((n - 1) * (__int128) (n - 1)) % mod) * (__int128) dp[i - 1][1]) % mod + ((2 * (n - 1)) * (__int128) dp[i - 1][0]) % mod) * d) % mod;
        dp[i][0] = (((((2) % mod) * dp[i - 1][1]) % mod + ((1 + ((n - 1) * (__int128) (n - 1)) % mod + (2 * (n - 2) + mod) % mod) * (__int128) dp[i - 1][0]) % mod) * d) % mod;
    }
    int sm = (((n * (__int128) (n + 1)) % mod * inv(2)) % mod - 1 + mod) % mod;
    int ans = (dp[k][1] + (sm * dp[k][0]) % mod) % mod;

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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