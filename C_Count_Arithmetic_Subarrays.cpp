#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> dp(n);
    int prv = INF;
    for(int i = 0; i < n; i++) {
        if(i)
            dp[i] = 1;
        if(i > 0 && v[i] - v[i - 1] == prv) {
            dp[i] += dp[i - 1];
        }
        if(i > 0)
            prv = v[i] - v[i - 1];
    }
    int ans = accumulate(dp.begin(), dp.end(), 0LL);
    ans += n;

    cout<<ans<<endl;
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