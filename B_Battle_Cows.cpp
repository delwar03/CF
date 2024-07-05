#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
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
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int me = v[k - 1], f = 0, id = -1;
    for(int i = k - 2; i >= 0; i--) {
        if(v[i] > me) f = 1, id = i;
    }
    int ans = 0;
    if(f) {
        int ind = 1, cnt = 0;
        swap(v[0], v[k - 1]);
        while(ind < n && v[ind] < me) {
            ind++;
            cnt++;
        }
        ans = max(ans, cnt);
        swap(v[0], v[k - 1]);
        swap(v[id], v[k - 1]);
        cnt = 0, ind = id + 1;
        while(ind < n && v[ind] < me) {
            ind++;
            cnt++;
        }
        if(id != 0) cnt++;
        ans = max(ans, cnt);
    } else {
        swap(v[0], v[k - 1]);
        int ind = 1, cnt = 0;
        while(ind < n && v[ind] < me) {
            cnt++;
            ind++;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
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