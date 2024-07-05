#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

vector<vector<int>> g[N];
vector<int> vis(N), dist(N);

void dfs(int node) {
    vis[node] = 1;
    for(auto it : g[node]) {
        int child = it[0];
        int wt = it[1];
        if(!vis[child]) {
            dist[child] = dist[node] + wt;
            dfs(child);
        }
    }
}

void reset(int n) {
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        dist[i] = vis[i] = 0;
    }
}

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> edges;
    reset(n);

    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, -wt});
        edges.push_back({u, v, wt});
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    for(auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        if(dist[u] + wt != dist[v]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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