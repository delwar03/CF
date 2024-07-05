#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

int inv[N], fact[N], revFact[N];

void solve() {
    int n; cin>>n;
    int m = 26;

    auto nCr = [&] (int n, int r) {
        return (((fact[n] * revFact[r]) % mod) * revFact[n - r]) % mod;
    };


    vector<int> c(m + 1);
    for(int i = 1; i <= m; i++) cin>>c[i];
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);
    
    dp[0][0] = 1;

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= c[i]; j++) {
            for(int len = 0; len + j <= n; len++) {
                int finalLen = len + j;
                dp[i][finalLen] = (dp[i][finalLen] + nCr(finalLen, j) * dp[i - 1][len]) % mod;
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans = (ans + dp[m][i]) % mod;
    }

    cout<<ans<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    inv[1] = 1;
    for(int a = 2; a < N; a++) {
        inv[a] = mod - (mod / a) * inv[mod % a] % mod;
    }

    // for(int i = 0; i < 100; i++) cerr<<inv[i]<<" "; cerr<<endl;

    fact[0] = fact[1] = revFact[0] = revFact[1] = 1;

    for(int i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        revFact[i] = (revFact[i - 1] * inv[i]) % mod;
    }

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/