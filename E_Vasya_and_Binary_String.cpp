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
    int n; cin>>n;
    string s; cin>>s;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector dp(n, vector(n, vector<int>(n, -1)));

    function<int(int, int, int)> magic = [&] (int l, int r, int f) {
        if(l == r) return v[f];
        int &ans = dp[l][r][f];
        if(~ans) return ans;
        ans = v[f] + magic(l + 1, r, 0);
        for(int i = l + 1; i <= r; i++) if(s[i] == s[l]) {
            if(i == l + 1) ans = max(ans, magic(l + 1, r, f + 1));
            else ans = max(ans, magic(l + 1, i - 1, 0) + magic(i, r, f + 1));
        }
        return ans;
    };

    cout<<magic(0, n - 1, 0)<<endl;
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