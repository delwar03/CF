#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[20][20][2][2]; // (ind, cnt, tight, started)

void solve() {
    int l, r; cin>>l>>r;
    vector<int> v(10);
    for(auto &x : v) cin>>x;
    string s;
    int cur;

    function<int(int, int, int, int)> magic = [&] (int ind, int cnt, int tight, int started) {
        if(ind == s.size()) {
            return (int) (cnt == v[cur]);
        }

        int &ans = dp[ind][cnt][tight][started];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx; i++) {
            if(i == 0 && !started) {
                ans += magic(ind + 1, cnt, tight & (i == mx), 0);
            } else {
                ans += magic(ind + 1, cnt + (i == cur), tight & (i == mx), 1);
            }
        }

        return ans;
    };


    auto cnt = [&] (int n) {
        s = to_string(n);
        int ans = 0;
        for(int i = 0; i <= 9; i++) {
            cur = i;
            memset(dp, -1, sizeof dp);
            ans += magic(0, 0, 1, 0);
        }
        
        return n - ans;
    };

    cout<<cnt(r) - cnt(l - 1)<<endl;
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