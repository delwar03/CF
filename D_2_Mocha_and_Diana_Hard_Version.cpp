#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

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
    int n, m1, m2; cin>>n>>m1>>m2;
    DisjointSet ds1(n), ds2(n);

    for(int i = 0; i < m1; i++) {
        int u, v; cin>>u>>v;
        ds1.unionBySize(u, v);
    }
    for(int i = 0; i < m2; i++) {
        int u, v; cin>>u>>v;
        ds2.unionBySize(u, v);
    }
    vector<vector<int>> ans;
    for(int i = 2; i <= n; i++) {
        if(ds1.findPar(i) != ds1.findPar(1) && ds2.findPar(i) != ds2.findPar(1)) {
            ds1.unionBySize(1, i);
            ds2.unionBySize(1, i);
            ans.push_back({1, i});
        }
    }
    vector<int> vis(n + 1);

    vis[1] = 1;
    int l = 1, r = 1;

    while(1) {
        while(l <= n && (ds1.findPar(l) == ds1.findPar(1) || vis[ds1.findPar(l)])) l++;
        while(r <= n && (ds2.findPar(r) == ds2.findPar(1) || vis[ds2.findPar(r)])) r++;
        if(l > n || r > n) break;

        vis[ds1.findPar(l)] = vis[ds2.findPar(r)] = 1;
        ds1.unionBySize(l, r);
        ds2.unionBySize(l, r);
        ans.push_back({l, r});
    }
    
    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it[0]<<" "<<it[1]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 