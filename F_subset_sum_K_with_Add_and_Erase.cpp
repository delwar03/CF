#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int dp[5005]; // dp[i] = sum i bananur koto gulo way ache

void solve() {
    int q, k; cin>>q>>k;
    dp[0] = 1;

    while(q--) {
        char op;
        int x; cin>>op>>x;
        
        if(op == '+') {
            for(int i = k; i - x >= 0; i--) dp[i] = (dp[i] + dp[i - x]) % mod;
        } else {
            for(int i = x; i <= k; i++) dp[i] = (dp[i] - dp[i - x] + mod) % mod;
        }

        cout<<dp[k]<<endl;
    }
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