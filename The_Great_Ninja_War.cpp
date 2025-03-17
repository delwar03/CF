#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 2520;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[14][2520][512][2]; // (ind, rem, mask, tight)
int pwr[10][10];

void solve() {
    int l, r; cin>>l>>r;
    string s;

    function<int(int, int, int, int)> magic = [&] (int ind, int rem, int mask, int tight) {
        if(ind == s.size()) {
            for(int i = 1; i <= 9; i++) {
                if(mask & (1LL << (i - 1))) {
                    if(rem % i != 0) {
                        return 0LL;
                    }
                }
            }
            return 1LL;
        }

        int &ans = dp[ind][rem][mask][tight];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx; i++) {
            if(i == 0) {
                ans += magic(ind + 1, rem, mask, tight & (i == mx));
            } else {
                ans += magic(ind + 1, (rem + pwr[i][i]) % 2520, mask | (1LL << (i - 1)), tight & (i == mx));
            }
        }

        return ans;
    };

    auto cnt = [&] (int n) {
        s = to_string(n);
        int ans = 0;
        memset(dp, -1, sizeof dp);
        ans += magic(0, 0, 0, 1);
        return ans;
    };

    cout<<cnt(r) - cnt(l - 1)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 10; i++) {
        pwr[i][0] = 1;
        for(int j = 1; j < 10; j++) {
            pwr[i][j] = (pwr[i][j - 1] * i) % mod;
        }
    }

    // for(int i = 0; i < 10; i++) {
    //     for(int j = 0; j < 10; j++) {
    //         cerr<<pwr[i][j]<<" \n"[j == 9];
    //     }
    // }

    auto lcm = [&] (int a, int b) {
        return (a * b) / __gcd(a, b);
    };

    int l = 1;

    for(int i = 1; i <= 9; i++) l = lcm(l, i);
    // cerr<<l<<endl;

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