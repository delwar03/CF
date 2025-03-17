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
    int n; cin>>n;
    vector<int> g[n + 1], tmp[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n + 1), par(n + 1), vis(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        tmp[dep[u]].push_back(u);
        for(auto v : g[u]) {
            if(v ^ p) {
                dep[v] = dep[u] + 1;
                par[v] = u;
                dfs(v, u);
            }
        }
    };

    dfs(1, 0);

    int ans = n - 1, prv = 0, curSz = 0;

    for(int i = n - 1; i >= 0; i--) {
        for(auto u : tmp[i]) {
            int cur = u;
            while(cur && !vis[cur]) {
                vis[cur] = 1;
                curSz++;
                cur = par[cur];
            }
        }
        ans = min(ans, n - curSz + prv);
        prv += (int) tmp[i].size();
    }

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

/*
i/p: 
o/p: 
*/