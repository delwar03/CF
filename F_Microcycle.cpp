#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, m, startNode, endNode, f = 0;
vector<vector<int>> g[N], edges;
vector<int> par(N, -1), vis(N, 0), cycle, vec;

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

void dfs(int node) {
    
    vis[node] = 1;
    vec.push_back(node);
    if(node == endNode) cycle = vec;

    for(auto it : g[node]) {
        int child  = it[0];
        int wt = it[1];
        if(!vis[child]) {
            if(node == startNode && child == endNode) continue;
            dfs(child);
        }
    }
    vec.pop_back();
}

void reset() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        par[i] = -1;
        vis[i] = 0;
    }
    edges.clear();
}

void solve() {
    cin>>n>>m;
    reset();
    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
        edges.push_back({wt, u, v});
        par[v] = u;
    }
    DisjointSet ds(n);

    int mnWt = INF;
    sort(edges.rbegin(), edges.rend());
    for(auto it : edges) {
        int u = it[1];
        int v = it[2];
        int wt = it[0];

        if(ds.findPar(u) == ds.findPar(v)) {
            if(wt < mnWt) {
                mnWt = wt;
                startNode = u;
                endNode = v;
            }
        } 
        ds.unionBySize(u, v);
    }
    dfs(startNode);

    // cout<<"start : "<<startNode<<", end : "<<endNode<<endl;
    cout<<mnWt<<" "<<cycle.size()<<endl;
    for(auto it : cycle) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 