#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> g[n + 1];
    for(int i = 2; i <= n; i++) {
        int p; cin>>p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    string s; cin>>s;
    s = "#" + s; // SP

    vector<array<int, 2>> dp(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        dp[u][0] = dp[u][1] = 0;
        if(s[u] == 'S') dp[u][1] = INF;
        if(s[u] == 'P') dp[u][0] = INF;
        for(int v : g[u]) {
            if(v == p) continue;
            dfs(v, u);
            dp[u][0] += min(dp[v][0], dp[v][1] + 1);
            dp[u][1] += min(dp[v][1], dp[v][0] + 1);
        }
    };

    dfs(1, 0);
    cout<<min(dp[1][0], dp[1][1])<<endl;
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