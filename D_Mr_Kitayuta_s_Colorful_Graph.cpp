#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class DisjointSet {
    
public:
    vector<int> rank, parent, sz;
    
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }

    void unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
};

void solve() {
    int n, m; cin>>n>>m;
    vector<int> g[n + 1];
    vector<array<int, 3>> edges;
    for(int i = 0; i < m; i++) {
        int u, v, c; cin>>u>>v>>c;
        g[u].emplace_back(c);
        g[v].emplace_back(c);
        edges.push_back({u, v, c});
    }

    for(int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }

    vector<int> pf(n + 2);
    for(int i = 1; i <= n; i++) pf[i] = pf[i - 1] + (int) g[i].size();


    auto getPos = [&] (int u, int c) {
        return pf[u - 1] + lower_bound(g[u].begin(), g[u].end(), c) - g[u].begin();
    };

    DisjointSet ds(2 * m + 10);

    for(auto it : edges) {
        int u = it[0], v = it[1], col = it[2];
        int uPos = getPos(u, col), vPos = getPos(v, col);
        ds.unionBySize(uPos, vPos);
    }

    map<pair<int, int>, int> mp;
    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        if(g[u].size() > g[v].size()) swap(u, v);

        if(mp.count({u, v})) {
            cout<<mp[{u, v}]<<endl;
        } else {
            int ans = 0;
            for(auto col : g[u]) {
                if(binary_search(g[v].begin(), g[v].end(), col)) {
                    int uPos = getPos(u, col), vPos = getPos(v, col);
                    if(ds.findPar(uPos) == ds.findPar(vPos)) {
                        ans++;
                    }
                }
            }
            mp[{u, v}] = ans;
            cout<<ans<<endl;
        }
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