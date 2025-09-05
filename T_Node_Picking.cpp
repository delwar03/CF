#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    int n, m = 0; cin>>n;
    vector<int> deg(n + 1), g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v), g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    for(int i = 1; i <= n; i++) m += (deg[i] == 1);
    m /= 2;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    vector<int> siz(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        siz[u] = (deg[u] == 1);
        for(auto v : g[u]) if(v ^ p) {
            dfs(v, u);
            siz[u] += siz[v];
        }

        for(int i = 0; i <= min(siz[u], m); i++) dp[u][i] = INF;
        dp[u][0] = 0;
        if(siz[u] <= m) dp[u][siz[u]] = 1;
        for(auto v : g[u]) if(v ^ p) {
            for(int i = min(siz[u], m); i >= 0; i--) {
                for(int j = 0; j <= siz[v] && i + j <= m; j++) {
                    dp[u][i + j] = min(dp[u][i + j], dp[u][i] + dp[v][j]);
                }
            }
        }
    };

    int ans = INF;
    while(double(clock()) / CLOCKS_PER_SEC < 1) {
        int rt = 1 + rng() % n;
        dfs(rt, 0);
        ans = min(ans, dp[rt][m]);
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}