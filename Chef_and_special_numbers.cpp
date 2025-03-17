#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 504;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

int dp[20][504][512][2][2][2]; // (ind, rem, mask, lo_tight, hi_tight, last_5)

void solve() {
    string l, r;
    int k; cin>>l>>r>>k;

    while(l.size() < 19) l = "0" + l;
    while(r.size() < 19) r = "0" + r;

    function<int(int, int, int, int, int, int)> magic = [&] (int ind, int rem, int mask, int lo_tight, int hi_tight, int last_5) {
        if(ind == 19) {
            int cnt = 0;
            
            for(int i = 1; i <= 9; i++) {
                if(i != 5 && ((mask >> (i  - 1)) & 1)) {
                    if(rem % i == 0) {
                        cnt++;
                    }
                }
            }

            if(last_5 && ((mask >> (5 - 1)) & 1)) cnt++;

            return (int) (cnt >= k);
        }

        int &ans = dp[ind][rem][mask][lo_tight][hi_tight][last_5];
        if(~ans) return ans;

        ans = 0;
        int mn = lo_tight ? l[ind] - '0' : 0;
        int mx = hi_tight ? r[ind] - '0' : 9;

        for(int i = mn; i <= mx; i++) {
            ans += magic(ind + 1, (10 * rem + i) % 504, mask | (i ? (1LL << (i - 1)) : 0), lo_tight & (i == mn), hi_tight & (i == mx), (i == 5 || i == 0));
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, 0, 0, 1, 1, 0)<<endl;
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