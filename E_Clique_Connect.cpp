#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 504;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

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
    map<vector<int>, int> mp;
    vector<vector<int>> g[n + 1];

    while(m--) {
        int k, c; cin>>k>>c;
        int u; cin>>u;
        for(int i = 0; i < k - 1; i++) {
            int v; cin>>v;
            if(mp.count({u, v}) || mp.count({v, u})) {
                if(c < mp[{u, v}]) {
                    mp[{u, v}] = c;
                }
            } else {
                mp[{u, v}] = c;
            }
        }
    }

    vector<vector<int>> edges;

    map<vector<int>, int> vis;

    for(auto it : mp) {
        int u = it.first[0];
        int v = it.first[1];
        int wt = it.second;

        g[u].push_back({v, wt});
        g[v].push_back({u, wt});

        if(!vis.count({u, v}) && !vis.count({v, u})) {
            edges.push_back({wt, u, v});
        }
        vis[{u, v}] = vis[{v, u}] = 1;
    }

    sort(edges.begin(), edges.end());
    
    DisjointSet ds(n + 1);

    int cost = 0;

    vector<vector<int>> mst;

    for(auto it : edges) {
        int u = it[1];
        int v = it[2];
        int wt = it[0];

        if(ds.findPar(u) != ds.findPar(v)) {
            cost += wt;
            ds.unionBySize(u, v);
            mst.push_back({u, v});
        }
    }

    cout<<(mst.size() == n - 1 ? cost : -1)<<endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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