#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[20][1040][2]; // (ind, mask, tight)

void solve() {
    int l, r, k; cin>>l>>r>>k;
    string s;

    function<int(int, int, int, int)> magic = [&] (int ind, int num, int mask, int tight) {
        if(ind == s.size()) {
            if(__builtin_popcount(mask) <= k) {
                return num;
            }
            return 0LL;
        }

        int &ans = dp[ind][mask][tight];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx && __builtin_popcount(mask) <= k; i++) {
            if(i == 0 && !mask) {
                ans = (ans + magic(ind + 1, num, mask, tight & (i == mx))) % mod;
            } else {
                ans = (ans + magic(ind + 1, (10 * num + i) % mod, mask | (1LL << i), tight & (i == mx))) % mod;
            }
        }

        return ans;
    };

    auto sum = [&] (int x) {
        s = to_string(x);
        int ans = 0;
        memset(dp, -1, sizeof dp);
        ans += magic(0, 0, 0, 1); // (ind, mask, num, tight)
        return ans;
    };

    cout<<((sum(r) - sum(l - 1)) % mod + mod) % mod<<endl;
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