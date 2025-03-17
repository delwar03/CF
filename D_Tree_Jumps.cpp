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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> par(n + 1), g[n + 1], dep(n + 1);
    for(int i = 2; i <= n; i++) {
        cin>>par[i];
        g[par[i]].push_back(i);
        dep[i] = 1 + dep[par[i]];
    }

    vector<int> dp(n + 1), sm(n + 1), ord(n + 1);
    iota(ord.begin(), ord.end(), 0LL);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
        return dep[i] > dep[j];
    });

    for(int u : ord) {
        dp[u] = 1 + sm[dep[u] + 1];
        for(int v : g[u]) (dp[u] -= dp[v] - mod) %= mod;
        (sm[dep[u]] += dp[u]) %= mod;
    }

    int ans = (1 + sm[1]) % mod;
    cout<<ans<<endl;
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