#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[18][140][140][2]; // dp(ind, sum, rem, tight)

void solve() {
    int n; cin>>n;
    string s = to_string(n);

    int cur;

    function<int(int, int, int, int)> magic = [&] (int ind, int sum, int rem, int tight) {
        if(ind == s.size()) {
            return (int) (rem == 0 && sum == 0);
        }

        int &ans = dp[ind][sum][rem][tight];
        if(~ans) return ans;

        ans = 0;

        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx && sum - i >= 0; i++) {
            ans += magic(ind + 1, sum - i, (10 * rem + i) % cur, tight && (i == mx));
        }

        return ans;
    };

    int ans = 0;

    for(int sm = 1; sm < 140; sm++) {
        cur = sm;
        memset(dp, -1, sizeof dp);
        ans += magic(0, sm, 0, 1); // ind, sum, rem, tight
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto isDivisible = [&] (int n) {
        int sm = 0, tmp = n;
        while(tmp) {
            sm += tmp % 10;
            tmp /= 10;
        }
        return n % sm == 0;
    };

    // for(int i = 1; i <= 10000; i++) {
    //     if(isDivisible(i)) {
    //         cerr<<i<<endl;
    //     }
    // }

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