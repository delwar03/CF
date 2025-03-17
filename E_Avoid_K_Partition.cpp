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

// pf[j] - pf[i] = k
// pf[i] = pf[j] - k

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> dp(n);
    map<int, int> mp;
    int sm = 0, tot = 1;
    mp[0] = 1;

    for(int i = 0; i < n; i++) {
        sm += v[i];
        dp[i] = (tot - mp[sm - k] + mod) % mod;
        mp[sm] += dp[i]; mp[sm] %= mod;
        tot = (tot + dp[i]) % mod;
    }

    cout<<dp[n - 1]<<endl;
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