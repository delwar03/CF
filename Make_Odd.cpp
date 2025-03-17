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
    string s, t; cin>>s>>t;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> magic = [&] (int ind, int tot) {
        if(ind == n) return (int) (tot % 2 == 1);
        int &ans = dp[ind][tot];
        if(~ans) return ans;
        ans = 0;
        ans |= magic(ind + 1, (s[ind] - '0') + tot);
        ans |= magic(ind + 1, (t[ind] - '0') + tot);

        return ans;
    };

    cout<<(magic(0, 0) ? "YES" : "NO")<<endl;
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