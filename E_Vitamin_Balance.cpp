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
const int N = 5005;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

array<int, 3> dp[N][N];

void solve() {
    int n, x; cin>>n>>x;
    vector<pii> v[3];
    for(int i = 0; i < n; i++) {
        int a, b, c; cin>>a>>b>>c;
        --a;
        v[a].push_back({b, c});
    }

    auto get = [&] (vector<pii> cur) {
        vector<int> dp(x + 1);
        for(auto [b, c] : cur) {
            for(int i = x - c; i >= 0; i--) dp[i + c] = max(dp[i + c], dp[i] + b);
        }
        return dp;
    };

    auto aa = get(v[0]);
    auto bb = get(v[1]);
    auto cc = get(v[2]);

    int ans = 0;
    for(int i = 0; i <= x; i++) for(int j = 0; j + i <= x; j++) {
        ans = max(ans, min({aa[i], bb[j], cc[x - i - j]}));
    }
    cout<<ans<<endl;
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