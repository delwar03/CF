#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[505][505]; // (ind, oper)

void solve() {
    int n, l, k; cin>>n>>l>>k;
    vector<int> pos(n), val(n);
    for(auto &x : pos) cin>>x;
    for(auto &x : val) cin>>x;

    pos.push_back(l);


    function<int(int, int)> magic = [&] (int ind, int tot) {
        
        if(ind == n) return 0LL;

        int &ans = dp[ind][tot];
        if(~ans) return ans;
        ans = INF;

        for(int i = ind + 1; i <= ind + tot + 1 && i <= n; i++) {
            ans = min(ans, (pos[i] - pos[ind]) * val[ind] + magic(i, tot - (i - ind - 1)));
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, k)<<endl;
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