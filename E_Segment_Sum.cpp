#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[20][1040][2]; // (ind, mask, tight)
int ndp[20][1040][2]; // (ind, mask, tight)
int pwr[25];

void solve() {
    int l, r, k; cin>>l>>r>>k;
    string s;
    int sz;

    function<int(int, int, int)> func = [&] (int ind, int mask, int tight) {

        if(ind == sz) return (int) (__builtin_popcount(mask) <= k);

        int &ans = ndp[ind][mask][tight];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx; i++) {
            ans += func(ind + 1, (i == 0 && !mask) ? mask : mask | (1LL << i), tight & (i == mx));
            ans %= mod;
        }

        return ans;
    };

    function<int(int, int, int)> magic = [&] (int ind, int mask, int tight) {

        if(ind == sz) return 0LL;

        int &ans = dp[ind][mask][tight];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx && __builtin_popcount(mask) <= k; i++) {

            int val = (i * pwr[sz - 1 - ind]) % mod;
            
            int cnt = func(ind + 1, (i == 0 && !mask) ? mask : mask | (1LL << i), tight & (i == mx));

            ans += (val * cnt) % mod + magic(ind + 1, (i == 0 && !mask) ? mask : mask | (1LL << i), tight & (i == mx));
            ans %= mod;
        }

        return ans;
    };

    auto sum = [&] (int x) {
        s = to_string(x);
        sz = s.size();
        int ans = 0;
        memset(dp, -1, sizeof dp);
        memset(ndp, -1, sizeof ndp);
        ans += magic(0, 0, 1); // (ind, mask, tight)
        return ans;
    };

    cout<<(sum(r) - sum(l - 1)+ mod) % mod<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pwr[0] = 1;

    for(int i = 1; i < 25; i++) {
        pwr[i] = (pwr[i - 1] * 10) % mod;
    }

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