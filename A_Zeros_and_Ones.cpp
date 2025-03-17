#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int dp[45][45][45][2][2]; // (ind, one_cnt, zero_cnt, tight, started)

void solve() {
    int x, y, mod, k; cin>>x>>y>>mod>>k;

    function<int(int, int, int, int, int, int)> magic = [&] (int ind, int one_cnt, int zero_cnt, int tight, int started, int num) {
        if(ind == 45) {
            if(one_cnt == x && zero_cnt == y) {
                // cerr<<num<<endl;
                return (int) ((num % mod) >= k);
            }
            return 0LL;
        }

        int &ans = dp[ind][one_cnt][zero_cnt][tight][started];
        if(~ans) return ans;

        ans = 0;
        int mx = 1;

        for(int i = 0; i <= mx; i++) {
            if(i == 0 && !started) {
                ans += magic(ind + 1, one_cnt, zero_cnt, tight & (i == mx), 0, 0);
            } else {
                ans += magic(ind + 1, one_cnt + (i == 1), zero_cnt + (i == 0), tight & (i == mx), 1, 2 * num + i); // 1001
            }
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, 0, 0, 1, 0, 0)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("zeros.in", "r", stdin);
    // freopen("zeros.in", "w", stdout);

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