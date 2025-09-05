#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    string s; cin>>s;
    int n = sz(s);

    vector dp(n, vector<int>(n)), f(n, vector<int>(n));
    for(int i = 0; i < n; i++) dp[i][i] = f[i][i] = 1;
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; i + j < n; j++) { // [i, i + j]
            f[i][i + j] = (j > 1 ? f[i + 1][i + j - 1] : 1) && (s[i] == s[i + j]);
            dp[i][i + j] = dp[i + 1][i + j] + dp[i][i + j - 1] - dp[i + 1][i + j - 1] + f[i][i + j];
        }
    }

    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        --l; --r;
        cout<<dp[l][r]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}