#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

int dp[N][12][2]; // (ind, prv, tight)
int ndp[N][2]; // (ind, prv, tight)
int pwr[N];

void solve() {
    int nl, nr;
    string l, r; cin>>nl>>l>>nr>>r;

    string s;
    int sz;

    function<int(int, int)> func = [&] (int ind, int tight) {

        if(ind == sz) return 1LL;

        int &ans = ndp[ind][tight];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx; i++) {
            ans += func(ind + 1, tight & (i == mx));
            ans %= mod;
        }

        return ans;
    };

    function<int(int, int, int)> magic = [&] (int ind, int prv, int tight) {
        if(ind == sz) {
            return 0LL;
        }

        int &ans = dp[ind][prv][tight];
        if(~ans) return ans;

        int mx = tight ? s[ind] - '0' : 9;

        ans = 0;

        for(int i = 0; i <= mx; i++) {
            if(i == prv) {
                ans += magic(ind + 1, i, tight & (i == mx));
                ans %= mod;
            } else {
                int cnt = func(ind + 1, tight & (i == mx));
                ans += ((i * pwr[sz - ind - 1]) % mod * cnt) % mod;
                ans += magic(ind + 1, i, tight & (i == mx));
                ans %= mod;
            }
        }

        return ans;
    };

    auto sum = [&] (string x) {
        s = x;
        sz = s.size();
        int ans = 0;
        memset(dp, -1, sizeof dp);
        memset(ndp, -1, sizeof ndp);
        ans += magic(0, 10, 1); // (ind, prv, tight)
        return ans;
    };

    int i = nl - 1;

    while(l[i] == '0') i--;
    l[i] = l[i] - 1;
    for(int j = i + 1; j < nl; j++) l[j] = '9';

    // cerr<<l<<" "<<r<<endl;

    int ans = (sum(r) - sum(l) + mod) % mod;

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pwr[0] = 1;

    for(int i = 1; i < N; i++) {
        pwr[i] = (pwr[i - 1] * 10) % mod;
    }

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