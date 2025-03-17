#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
// 012
// RPS
// PSR
// 120

// (v[ind] + 1) % 3 == i

// (i + 1) % 3 == v[ind]

int dp[N][5];

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') v.push_back(0);
        if(s[i] == 'P') v.push_back(1);
        if(s[i] == 'S') v.push_back(2);
    }

    // for(auto it : v) cerr<<it<<" ";

    function<int(int, int)> magic = [&] (int ind, int prv) {
        if(ind == n) return 0LL;

        int &ans = dp[ind][prv];
        if(~ans) return ans;

        ans = 0;

        for(int i = 0; i < 3; i++) {
            if(i == prv) continue;
            int f = (v[ind] == (i + 1) % 3);
            if(f) continue;
            f = (i == (v[ind] + 1) % 3);
            ans = max(ans, f + magic(ind + 1, i));
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, 4)<<endl;
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