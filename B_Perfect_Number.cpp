#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[20][12][2]; // (ind, sum, tight)

void solve() {
    int k; cin>>k;
    string s;

    function<int(int, int, int)> magic = [&] (int ind, int sum, int tight) {
        if(ind == s.size()) return (int) (sum == 0);

        int &ans = dp[ind][sum][tight];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx && sum - i >= 0; i++) {
            ans += magic(ind + 1, sum - i, tight & (i == mx));
        }

        return ans;
    };

    int l = 0, r = INF, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        s = to_string(mid);
        memset(dp, -1, sizeof dp);
        int cnt = magic(0, 10, 1);

        if(cnt >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout<<ans<<endl;
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