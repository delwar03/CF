#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[20][20][2]; // dp(ind, dif, tight)

void solve() {
    int n, k; cin>>n>>k;
    string s = to_string(n);

    function<int(int, int, int, int)> magic = [&] (int num, int ind, int mask, int tight) {
        if(ind == s.size()) {
            return __builtin_popcount(mask) <= k ? num : INF;
        }

        int &ans = dp[ind][__builtin_popcount(mask)][tight];
        if(~ans) return ans;

        ans = INF;

        int mn = tight ? s[ind] - '0' : 0;

        for(int i = mn; i <= 9 && __builtin_popcount(mask) <= k; i++) {
            ans = min(ans, magic(10 * num + i, ind + 1, mask | (1LL << i), tight && (i == mn)));
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, 0, 0, 1)<<endl; // num, ind, dif, tight 
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