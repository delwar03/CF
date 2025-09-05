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
    int n, l, k; cin>>n>>l>>k;
    vector<int> pos(n), val(n);
    for(int &x : pos) cin>>x;
    for(int &x : val) cin>>x;

    pos.push_back(l);

    vector dp(n + 1, vector<int>(k + 1, -1));

    function<int(int, int)> magic = [&] (int ind, int tot) {
        if(ind == n) return 0LL;
        int &ans = dp[ind][tot];
        if(~ans) return ans;
        ans = INF;
        for(int i = ind + 1; i - ind - 1 <= tot && i <= n; i++) {
            ans = min(ans, (pos[i] - pos[ind]) * val[ind] + magic(i, tot - (i - ind - 1)));
        }
        return ans;
    };

    cout<<magic(0, k)<<endl;
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