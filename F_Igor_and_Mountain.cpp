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
    int n, m, d; cin>>n>>m>>d;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    int sq = sqrtl(d * d - 1);

    vector dp(n, vector<int>(m, -1));

    function<int(int, int)> magic = [&] (int i, int j) {
        if(i == n - 1) return 1LL;
        int &ans = dp[i][j];
        if(~ans) return ans;
        ans = 0;
        for(int k = -d; k <= d; k++) if(k && 0 <= j + k && j + k < m && v[i][j + k] == 'X') (ans += magic(i, j + k)) %= mod;
        for(int k = -sq; k <= sq; k++) if(k && i + 1 < n && 0 <= j + k && j + k < m && v[i + 1][j + k] == 'X') (ans += magic(i + 1, j + k)) %= mod;
        return ans;
    };

    int ans = 0;
    for(int j = 0; j < m; j++) if(v[0][j] == 'X') (ans += magic(0, j)) %= mod;
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}