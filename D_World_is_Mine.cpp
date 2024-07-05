#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> magic = [&] (int ind, int tot) {

        if(ind > n) return 0LL;

        int &ans = dp[ind][tot];
        if(!!~ans) return ans;

        ans = 1 + magic(ind + 1, tot + 1);
        if(tot >= cnt[ind])
            ans = min(ans, magic(ind + 1, tot - cnt[ind]));

        return ans;
    };

    cout<<magic(0, 0)<<endl;
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