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
    int n; cin>>n;
    vector<int> pos(n + 1);
    vector<int> g[n + 1], rev[n + 1];
    for(int i = 1; i <= n; i++) {
        int v; cin>>v;
        g[i].push_back(v);
        rev[v].push_back(i);
        pos[i] = v;
    }

    vector<int> vis(n + 1, 0);
    vector<int> topo;

    function<void(int)> dfs1 = [&] (int u) {
        vis[u] = 1;
        for(auto v : g[u]) {
            if(!vis[v]) {
                dfs1(v);
            }
        }
        topo.push_back(u);
    };

    for(int i = 1; i <= n; i++) if(!vis[i]) {
        dfs1(i);
    }

    reverse(topo.begin(), topo.end());

    // for(auto it : topo) cerr<<it<<" "; cerr<<endl;

    vis.assign(n + 1, 0);

    vector<int> cur;

    function<void(int)> dfs2 = [&] (int u) {
        vis[u] = 1;
        for(auto v : rev[u]) {
            if(!vis[v]) {
                dfs2(v);
            }
        }
        cur.push_back(u);
    };

    vector<vector<int>> SCC;

    for(auto it : topo) if(!vis[it]) {
        cur.clear();
        dfs2(it);
        SCC.push_back(cur);
    }

    reverse(SCC.begin(), SCC.end());
    int sz = (int) SCC.size();

    vector<int> dp(n + 1);

    for(auto it : SCC) {
        if(it.size() == 1) {
            dp[it[0]] = 1 + dp[pos[it[0]]];
        } else {
            for(auto u : it)
                dp[u] = (int) it.size();
        }
    }

    int ans = accumulate(dp.begin(), dp.end(), 0LL);

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

/*
i/p: 
o/p: 
*/