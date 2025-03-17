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

int dp[2005][2005];

void solve() {
    int n; cin>>n;
    vector<pii> v;
    for(int i = 0; i < n; i++) {
        int x; cin>>x; 
        v.push_back({x, i});
    }
    sort(v.rbegin(), v.rend());

    function<int(int, int, int)> magic = [&] (int ind, int i, int j) {
        if(ind == n) return 0LL;
        int &ans = dp[i][j];
        if(~ans) return ans;

        ans = 0;
        ans = max(ans, v[ind].F * abs(v[ind].S - i) + magic(ind + 1, i + 1, j));
        ans = max(ans, v[ind].F * abs((n - j - 1) - v[ind].S) + magic(ind + 1, i, j + 1));

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, 0, 0)<<endl;
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