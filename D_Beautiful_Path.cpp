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
const double eps = 1e-10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    vector<array<int, 3>> g[n + 1];

    for(int i = 0; i < m; i++) {
        int u, v, b, c; cin>>u>>v>>b>>c;
        g[u].push_back({v, b, c});
        g[v].push_back({u, b, c});
    }

    auto f = [&] (double x) {
        vector<double> dp(n + 1, -INF);
        dp[1] = 0;
        for(int u = 1; u < n; u++) {
            for(auto [v, b, c] : g[u]) {
                dp[v] = max(dp[v], dp[u] + b - x * c);
            }
        }
        return dp[n] >= 0;
    };

    double l = 0, r = INF, best = 0;
    while(r - l >= eps) {
        double mid = (l + r) / 2;
        if(f(mid)) {
            best = mid;
            l = mid;
        } else {
            r = mid;
        }
    }

    cout<<fixed<<setprecision(10);
    cout<<best<<endl;
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