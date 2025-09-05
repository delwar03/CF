#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e2 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> di[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int mx = *max_element(v.begin(), v.end());
    vector<int> dp(n), cnt(mx + 1);

    for(int i = 0; i < n; i++) {
        int x = v[i];
        dp[i] = i;
        if(x != 1) {
            for(int j : di[x]) dp[i] -= cnt[j];
            for(int j = 2 * x; j <= mx; j += x) dp[i] -= cnt[j];
            for(int j : di[x]) cnt[j]++;
        } else {
            cnt[x]++;
        }
    }

    for(int i = 0; i < n; i++) cerr<<dp[i]<<" \n"[i == n - 1];

    cout<<accumulate(dp.begin(), dp.end(), 0LL)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i) {
            di[j].push_back(i);
        }
    }

    // for(int i = 1; i <= 100; i++) {
    //     cerr<<i<<" -> ";
    //     for(int j : di[i]) cerr<<j<<" "; cerr<<endl;
    // }

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}