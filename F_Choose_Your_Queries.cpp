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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    vector<int> g[n + 1];
    vector<array<int, 3>> edges;
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v, i});
    }

    vector<pair<int, int>> ans;
    vector<int> vis(n + 1), odd(n + 1);
    int timer = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        vis[u] = ++timer;
        for(auto v : g[u]) {
            if(v == p) continue;
            if(!vis[v]) {
                dfs(v, u);
                if(odd[v]) {
                    ans.push_back({v, u});
                    odd[v] ^= 1;
                } else {
                    ans.push_back({u, v});
                    odd[u] ^= 1;
                }
            } else if(vis[v] < vis[u]) {
                ans.push_back({u, v});
                odd[u] ^= 1;
            }
        }
    };

    for(int i = 1; i <= n; i++) if(!vis[i]) {
        dfs(i, 0);
    }

    map<pair<int, int>, int> mp;

    for(auto &[u, v] : ans) {
        cerr<<u<<" "<<v<<endl;
        mp[{u, v}] = 1;
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

/*
i/p: 
o/p: 
*/