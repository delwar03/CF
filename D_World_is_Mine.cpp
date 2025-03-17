#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> freq(n + 1);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        freq[x]++;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> magic = [&] (int cur, int tot) {
        if(cur == n + 1) return 0LL;
        int &ans = dp[cur][tot];
        if(~ans) return ans;

        ans = INF;

        if(freq[cur]) ans = min(ans, 1 + magic(cur + 1, tot + 1));
        if(tot >= freq[cur]) ans = min(ans, magic(cur + 1, tot - freq[cur]));

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