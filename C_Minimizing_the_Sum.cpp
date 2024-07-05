#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    function<int(int, int)> magic = [&] (int ind, int k) {
        if(ind <= 0) return 0LL;
        int &ans = dp[ind][k];
        if(~ans) return ans;

        int mn = INF, cur = INF;
        
        for(int i = ind; i >= max(1LL, ind - k); i--) {
            cur = min(cur, v[i]);
            int len = ind - i + 1;
            mn = min(mn, len * cur + magic(i - 1, k - len + 1));
        }

        return ans = mn;
    };

    cout<<magic(n, k)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/