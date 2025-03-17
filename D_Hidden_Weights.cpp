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
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    vector<array<int, 2>> g[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, -wt});
    }

    vector<int> vis(n + 1), val(n + 1);

    function<void(int, int)> dfs = [&] (int u, int f) {
        val[u] = f;
        vis[u] = 1;
        for(auto [v, wt] : g[u]) {
            if(!vis[v]) {
                dfs(v, f + wt);
            }
        }
    };

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, 0);
        }
    }

    for(int i = 1; i <= n; i++) cout<<val[i]<<" ";
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

/*
i/p: 
o/p: 
*/