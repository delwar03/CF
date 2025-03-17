#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
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
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    vector<int> col(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) col[j] |= (v[i][j] == '1') << i;
    }

    // for(int x : col) cerr<<x<<" "; cerr<<endl;

    int mask = 1LL << n;
    vector<vector<int>> dp(n + 1, vector<int>(mask));

    for(int i = 0; i < m; i++) dp[0][col[i]] += 1;

    for(int k = 1; k <= n; k++) {
        for(int j = 0; j < mask; j++) {
            int sm = (k - 2 >= 0 ? (k - 2 - n) * dp[k - 2][j] : 0);
            for(int p = 0; p < n; p++) sm += dp[k - 1][j ^ (1LL << p)];
            dp[k][j] = sm / k;
        }
    }

    int ans = INF;

    for(int i = 0; i < mask; i++) {
        int cur = 0;
        for(int k = 0; k <= n; k++) cur += min(k, n - k) * dp[k][i];
        ans = min(ans, cur);
    }

    cout<<ans<<endl;
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