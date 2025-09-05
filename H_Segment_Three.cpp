#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<vector<int>> dp(n + 1, vector<int>(3, -1));

    function<int(int, int)> magic = [&] (int i, int md) {
        if(i == n) return (md == 0 ? 0 : INF);
        int &ans = dp[i][md];
        if(~ans) return ans;
        ans = INF;
        ans = min(ans, magic(i + 1, ((i - 3 >= 0 ? 3 - (v[i - 3] % 3) : 0) + md + v[i]) % 3));
        ans = min(ans, 1 + magic(i + 1, ((i - 3 >= 0 ? 3 - (v[i - 3] % 3) : 0) + md + 1 + v[i]) % 3));
        ans = min(ans, 2 + magic(i + 1, ((i - 3 >= 0 ? 3 - (v[i - 3] % 3) : 0) + md + 2 + v[i]) % 3));
        return ans;
    };
    
    cout<<magic(0, 0)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}