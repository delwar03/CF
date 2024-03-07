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
    int n; cin>>n;
    vector<string> v(n);
    for(auto &x : v) cin>>x;
    vector<int> r(n), c(n);
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            cnt += (v[i][j] == 'o');
        }
        r[i] = cnt;
    }
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            cnt += (v[j][i] == 'o');
        }
        c[i] = cnt;
    }
    // for(auto it : r) cout<<it<<" "; cout<<endl;
    // for(auto it : c) cout<<it<<" "; cout<<endl;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == 'o') ans += max(0LL, r[i] - 1) * max(0LL, c[j] - 1);
        }
    }

    cout<<ans<<endl;
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