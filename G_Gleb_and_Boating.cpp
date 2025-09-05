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
    int s, k; cin>>s>>k;
    vector dp(k + 1, vector<int>(2 * k + 1, -1));

    function<int(int, int)> magic = [&] (int cur, int st) {
        if(cur < 2) return 1LL;
        if((s - st) % cur == 0) return cur;
        int &ans = dp[cur][st];
        if(~ans) return ans;
        ans = 0;
        int kk = min(k, (s - st) / cur);
        for(int i = 1; i <= kk && st + i <= k; i++) {
            ans = max(ans, magic(cur - 2, st + i));
        }
        return ans;
    };
    
    int ans = magic(k, 0);
    ans = max(1LL, ans);
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