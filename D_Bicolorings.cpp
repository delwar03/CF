#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[1005][2005][6]; // (col, comp, mask)

void solve() {
    int n, k; cin>>n>>k;

    function<int(int, int, int)> magic = [&] (int col, int comp, int mask) {
        if(col == n) {
            return (int) (comp == k);
        }

        int &ans = dp[col][comp][mask];
        if(~ans) return ans;

        ans = 0;

        if(mask == 0) {
            ans = (ans + magic(col + 1, comp, 0)) % mod;
            ans = (ans + magic(col + 1, 1 + comp, 1)) % mod;
            ans = (ans + magic(col + 1, 1 + comp, 2)) % mod;
            ans = (ans + magic(col + 1, 1 + comp, 3)) % mod;
        } else if(mask == 1) {
            ans = (ans + magic(col + 1, comp, 0)) % mod;
            ans = (ans + magic(col + 1, comp, 1)) % mod;
            ans = (ans + magic(col + 1, 2 + comp, 2)) % mod;
            ans = (ans + magic(col + 1, comp, 3)) % mod;
        } else if(mask == 2) {
            ans = (ans + magic(col + 1, comp, 0)) % mod;
            ans = (ans + magic(col + 1, 2 + comp, 1)) % mod;
            ans = (ans + magic(col + 1, comp, 2)) % mod;
            ans = (ans + magic(col + 1, comp, 3)) % mod;
        } else if(mask == 3) {
            ans = (ans + magic(col + 1, 1 + comp, 0)) % mod;
            ans = (ans + magic(col + 1, 1 + comp, 1)) % mod;
            ans = (ans + magic(col + 1, 1 + comp, 2)) % mod;
            ans = (ans + magic(col + 1, comp, 3)) % mod;
        } else {
            ans = (ans + magic(col + 1, 1 + comp, 0)) % mod;
            ans = (ans + magic(col + 1, 2 + comp, 1)) % mod;
            ans = (ans + magic(col + 1, 2 + comp, 2)) % mod;
            ans = (ans + magic(col + 1, 1 + comp, 3)) % mod;
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, 0, 4)<<endl;
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