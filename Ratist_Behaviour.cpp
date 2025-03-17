#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 504;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];
    string s; cin>>s;
    s = "#" + s;

    int dp[n + 5][2]; // (ind, retist)

    function<int(int, int)> magic = [&] (int ind, int retist) {
        if(ind == n + 1) return 0LL;

        int &ans = dp[ind][retist];
        if(~ans) return ans;

        ans = 0;

        if(retist) {
            if(v[ind] >= v[ind - 1]) {
                ans = max(ans, 1 + magic(ind + 1, s[ind] - '0'));
            } else {
                ans = max(ans, magic(ind + 1, retist));
            }
        } else {
            ans = 1 + magic(ind + 1, s[ind] - '0');
        }

        return ans;
    };

    // memset(dp, -1, sizeof dp);
    // cout<<magic(1, 0)<<endl;

    map<int, int> mp;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0') {
            ans++;
        } else {
            mp[v[i]]++;
        }
    }
    int mx = 0, ind = 0;
    for(auto it : mp) {
        if(it.second > mx) {
            mx = it.second;
            ind = it.first;
        }
    }

    ans += mx;
    mp.erase(ind);

    mx = 0, ind = 0;
    for(auto it : mp) {
        if(it.second > mx) {
            mx = it.second;
            ind = it.first;
        }
    }

    // cerr<<mx<<endl;

    if(ans + mx < n) ans += mx;


    cout<<ans<<endl;
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