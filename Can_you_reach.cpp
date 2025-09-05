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
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> dp(n), cnt(n);

    int ct1 = 0, ct2 = 0, sm1 = 0, sm2 = 0;

    for(int i = 1; i < n; i++) {
        if(v[i] < v[i - 1]) {
            cnt[i] = dp[i] = ++ct1, ct2 = 0;
            if(i - 2 >= 0 && v[i - 1] > v[i - 2]) sm1 = cnt[i - 1];
            dp[i] += (sm1 - ct1 * (ct1 - 1) / 2);
            sm1 += cnt[i], sm2 = 0;
        } else {
            cnt[i] = dp[i] = ++ct2, ct1 = 0;
            if(i - 2 >= 0 && v[i - 1] < v[i - 2]) sm2 = cnt[i - 1];
            dp[i] += (sm2 - ct2 * (ct2 - 1) / 2);
            sm2 += cnt[i], sm1 = 0;
        }
    }

    // for(int i = 0; i < n; i++) cerr<<dp[i]<<" \n"[i == n - 1];

    cout<<accumulate(dp.begin(), dp.end(), 0LL)<<endl;
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