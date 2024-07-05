#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[200005][15]; // (ind, digit)

void solve() {
    int n; cin>>n;

    auto binPow = [&] (int a, int b) {
        int res = 1;
        while(b > 0) {
            if(b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    };
    
    for(int len = 1; len < n; len++) {
        int ans = 0;
        ans = (ans + 2 * 10 * 9 * binPow(10, n - len - 1)) % mod;
        ans = (ans + (n - len - 1) * 10 * (9 * 9) * binPow(10, n - len - 2)) % mod;
        cout<<ans<<" ";
    }
    cout<<10<<endl;
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