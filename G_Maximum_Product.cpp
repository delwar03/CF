#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[20][2][2][2]; // (ind, lo_tight, hi_tight, started)

void solve() {
    string l, r; cin>>l>>r;
    int mx = 0;

    function<int(int, int, int, int)> magic = [&] (int ind, int lo_tight, int hi_tight, int started) {
        if(ind == r.size()) return 1LL;

        int &ans = dp[ind][lo_tight][hi_tight][started];
        if(~ans) return ans;

        int mn = lo_tight ? l[ind] - '0' : 0;
        int mx = hi_tight ? r[ind] - '0' : 9;

        for(int i = mn; i <= mx; i++) {
            ans = max(ans, magic(ind + 1, lo_tight & (i == mn), hi_tight & (i == mx), started | (i != 0)) * ((!i && !started) ? 1 : i));
        }

        return ans;
    };

    function<void(int, int, int, int)> print = [&] (int ind, int lo_tight, int hi_tight, int started) {
        if(ind == r.size()) return;

        int val = dp[ind][lo_tight][hi_tight][started];

        int mn = lo_tight ? l[ind] - '0' : 0;
        int mx = hi_tight ? r[ind] - '0' : 9;

        for(int i = mn; i <= mx; i++) {
            if((magic(ind + 1, lo_tight & (i == mn), hi_tight & (i == mx), started | (i != 0)) * ((!i && !started) ? 1 : i)) == val) {
                if(started || i) cout<<i;
                print(ind + 1, lo_tight & (i == mn), hi_tight & (i == mx), started | (i != 0));
                return;
            }
        }
    };

    while(l.size() < r.size()) l = "0" + l;

    memset(dp, -1, sizeof dp);
    mx = magic(0, 1, 1, 0);
    // cerr<<"mx: "<<mx<<endl;

    print(0, 1, 1, 0);
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