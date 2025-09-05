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
    int n; cin>>n;
    vector<int> val(n), g[n];
    for(auto &x : val) cin>>x;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<int> mx(val.begin(), val.end()), mn(n, INF);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) if(v ^ p) {
            mn[v] = min(mn[v], -mx[u] + val[v]);
            mx[v] = max(mx[v], -mn[u] + val[v]);
            dfs(v, u);
        }
    };

    dfs(0, -1);

    for(int i = 0; i < n; i++) cout<<mx[i]<<" \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}   