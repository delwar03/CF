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
    vector<int> v(n + 1), pf(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i], pf[i] = pf[i - 1] ^ v[i];

    vector<int> dp(n + 1);
    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        dp[i] = v[i];
        if(v[i] == v[i - 1]) {
            dp[i] += dp[i - 1];
        } else {
            if(mp.count(pf[i])) {
                dp[i] += dp[mp[pf[i]]];
            }
        }
        mp[pf[i - 1]] = i;
    }

    cout<<*max_element(dp.begin(), dp.end())<<endl;
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