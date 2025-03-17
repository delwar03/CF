#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<int> val(26);
    for(auto &x : val) cin>>x;

    int mxLen = 1;
    vector<int> dp(n + 1, 0), ndp(n + 1, INF);
    dp[0] = 1;
    ndp[0] = 0;

    for(int i = 1; i <= n; i++) {
        int cur = INF;
        for(int j = i - 1; j >= 0; j--) {
            int len = i - j;
            cur = min(cur, val[s[j] - 'a']);
            if(cur >= len) {
                dp[i] += dp[j];
                dp[i] %= mod;
                ndp[i] = min(ndp[i], 1 + ndp[j]);
                mxLen = max(mxLen, len);
            } else {
                break;
            }
        }
    }

    cout<<dp[n]<<"\n"<<mxLen<<"\n"<<ndp[n]<<endl;
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
