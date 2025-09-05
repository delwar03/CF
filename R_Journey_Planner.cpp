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
const int N = 1e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;
    while(cin>>n && n) {
        cin>>m;
        vector<int> g[n + 1];
        for(int i = 0; i < m; i++) {
            int u, v; cin>>u>>v;
            g[u].push_back(v);
        }

        vector<int> vis(n + 1), val(n + 1), sm(n + 1);
        int ct = 0;
        function<void(int)> dfs = [&] (int u) {
            vis[u] = 1;
            ct++;
            for(int v : g[u]) {
                if(!vis[v]) dfs(v);
                val[u] = max(val[u], val[v]);
            }
        };

        for(int iter = 0; iter < 100; iter++) {
            for(int i = 1; i <= n; i++) val[i] = rng() % mod, vis[i] = 0;
            for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
            for(int i = 1; i <= n; i++) sm[i] += val[i];
        }
        pii mx = {-1, -1};
        for(int i = 1; i <= n; i++) mx = max(mx, {sm[i], i}), vis[i] = 0;
        ct = 0;
        dfs(mx.S);
        cout<<mx.S<<" "<<ct<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}