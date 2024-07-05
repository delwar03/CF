#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
const double eps = 1e-10;

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> g[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v, b, c; cin>>u>>v>>b>>c;
        g[v].push_back({u, b, c});
    }

    vector<double> dp(n + 1);

    auto f = [&] (double x) {
        for(int u = 2; u <= n; u++) {
            dp[u] = -INF;
            for(auto it : g[u]) {
                int v = it[0], b = it[1], c = it[2];
                dp[u] = max(dp[u], dp[v] + b - c * x);
            }
        }
        return dp[n] >= 0;
    };

    double l = 0, r = INF, ans = 0;

    while(r - l >= eps) {
        double mid = (l + r) / 2;
        if(f(mid)) {
            l = ans = mid;
        } else {
            // cerr<<"yooo"<<endl;
            r = mid;
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/