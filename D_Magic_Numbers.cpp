#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[2005][2005][2][3]; // (ind, rem, tight, even/odd)

void solve() {
    int m, d; cin>>m>>d;
    string l, r; cin>>l>>r;
    string s;

    function<int(int, int, int, int)> magic = [&] (int ind, int rem, int tight, int f) {
        if(ind == s.size()) {
            return (int) (f != 2 && rem == 0);
        }

        int &ans = dp[ind][rem][tight][f];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;

        for(int i = 0; i <= mx; i++) {
            if(i == 0 && f == 2) {
                ans = (ans + magic(ind + 1, rem, tight & (i == mx), 2)) % mod;
            } else {
                if(f == 2 || f) {
                    if(i != d) {
                        ans = (ans + magic(ind + 1, (10 * rem + i) % m, tight & (i == mx), !f)) % mod;
                    }
                } else {
                    if(i == d) {
                        ans = (ans + magic(ind + 1, (10 * rem + i) % m, tight & (i == mx), !f)) % mod;
                    }
                }
            }
        }

        return ans;
    };

    auto cnt = [&] (string x) {
        s = x;
        int ans = 0;
        memset(dp, -1, sizeof dp);
        ans += magic(0, 0, 1, 2);
        return ans;
    };

    int ind = l.size() - 1;
    while(l[ind] == '0') ind--;
    l[ind] = l[ind] - 1;
    for(int i = ind + 1; i < l.size(); i++) l[i] = '9';

    cout<<(cnt(r) - cnt(l)+ mod) % mod<<endl;
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