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
    int n, k; cin>>n>>k;
    vector<int> par(n + 1), g[n + 1];
    for(int i = 2; i <= n; i++) {
        cin>>par[i];
        g[par[i]].push_back(i);
        g[i].push_back(par[i]);
    }

    vector<int> dp(n + 1, 1), kthPar(n + 1), child(n + 1);
    int ans = 0;

    function<void(int, int, int)> dfs = [&] (int u, int p, int d) {
        kthPar[u] = (d < k ? -1 : d == k ? 1 : child[kthPar[p]]);
        for(auto v : g[u]) if(v ^ p) {
            child[u] = v;
            dfs(v, u, d + 1);
        }
        if(d < k) ans += dp[u] * (dp[u] - 1) / 2;
        if(~kthPar[u]) dp[kthPar[u]] += dp[u];
    };

    dfs(1, 0, 0);

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