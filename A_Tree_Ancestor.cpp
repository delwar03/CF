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
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n + 1), par(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                par[v] = u;
                dep[v] = 1 + dep[u];
                dfs(v, u);
            }
        }
    };

    dfs(1, 0);

    vector<vector<int>> dp(32, vector<int>(n + 1));

    for(int i = 0; i <= 30; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i - 1 >= 0 ? dp[i - 1][dp[i - 1][j]] : par[j]);
        }
    }

    auto LCA = [&] (int u, int v) {
        if(dep[u] > dep[v]) swap(u, v);
        int k = dep[v] - dep[u];
        for(int i = 30; i >= 0; i--) if(k >> i & 1) v = dp[i][v];
        if(u == v) return u;
        
        for(int i = 30; i >= 0; i--) {
            if(dp[i][u] != dp[i][v]) {
                u = dp[i][u];
                v = dp[i][v];
            }
        }
        u = dp[0][u];
        v = dp[0][v];

        assert(u == v);

        return u;
    };

    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        cout<<(LCA(u, v) == u ? "YES" : "NO")<<endl;
    }
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