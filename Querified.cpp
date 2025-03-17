#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n, root; cin>>n>>root;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dp(n + 1);
    // iota(dp.begin(), dp.end(), 0LL);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u);
                if(v < u) 
                    dp[u] = max(dp[u], __gcd(u, dp[v]));
            }
        }
    };

    dfs(root, 0);

    for(int i = 1; i <= n; i++) {
        cout<<(dp[i] == 0 ? -1 : dp[i] / 2)<<" \n"[i == n];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
