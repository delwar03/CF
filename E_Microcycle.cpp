#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, m, st, en;
vector<int> vec, path, vis;
vector<vector<int>> g[N];

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

void reset() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
    vis.assign(n + 1, 0);
    path.clear();
    vec.clear();
}

void dfs(int node) {
    vis[node] = 1;
    vec.push_back(node);
    if(node == en) {path = vec; return;}
    for(auto it : g[node]) {
        int child = it[0];
        if(node == st && child == en) continue;
        if(vis[child]) continue;;
        dfs(child);
    }
    vec.pop_back();
}

void solve() {
    cin>>n>>m;
    reset();
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        // u--; v--;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
        edges.push_back({wt, u, v});
    }
    sort(edges.rbegin(), edges.rend());
    DisjointSet ds(n);
    int mn = INF;
    for(auto it : edges) {
        int u = it[1];
        int v = it[2];
        int wt = it[0];
        if(ds.findPar(u) == ds.findPar(v)) {
            mn = wt;
            st = u;
            en = v;
        }
        ds.unionBySize(u, v);
    }
    // cout<<"st: "<<st<<" en: "<<en<<endl;
    dfs(st);
    cout<<mn<<" "<<(int) path.size()<<endl;
    for(auto it : path) cout<<it<<" "; cout<<endl;
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