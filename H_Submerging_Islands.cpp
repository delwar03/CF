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
    while(1) {
        int n, m; cin>>n>>m;
        if(!n && !m) return;
        vector<int> g[n + 1];
        for(int i = 0; i < m; i++) {
            int u, v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> art(n + 1), vis(n + 1), in(n + 1), low(n + 1);
        int tt = 0;

        function<void(int, int)> dfs = [&] (int u, int p) {
            vis[u] = 1;
            in[u] = low[u] = tt++;
            int ct = 0;
            for(int v : g[u]) {
                if(v == p) continue;
                if(!vis[v]) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if(low[v] >= in[u] && p != -1) art[u] = 1;
                    ct += 1;
                } else {
                    low[u] = min(low[u], in[v]);
                }
            }
            if(ct > 1 && p == -1) art[u] = 1;
        };

        for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i, -1);

        cout<<accumulate(art.begin(), art.end(), 0LL)<<endl;
    }
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