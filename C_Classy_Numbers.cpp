#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[20][6][2]; // dp(ind, dif, tight)

void solve() {
    int l, r; cin>>l>>r;

    string s;
    int cur;

    int k = 3;

    function<int(int, int, int)> magic = [&] (int ind, int cnt, int tight) {
        if(ind == s.size()) {
            return (int) (cnt == 0);
        }

        int &ans = dp[ind][cnt][tight];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx && cnt >= 0; i++) {
            ans += magic(ind + 1, cnt - (i != 0), tight & (i == mx));
        }

        return ans;
    };


    auto sum = [&] (int x) {
        s = to_string(x);
        int ans = 0;
        for(int dif = 1; dif <= 3; dif++) {
            memset(dp, -1, sizeof dp);
            cur = dif;
            ans += magic(0, dif, 1); // ind, cnt, tight
        }
        return ans;
    };

    cout<<sum(r) - sum(l - 1)<<endl;
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