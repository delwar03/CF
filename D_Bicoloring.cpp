#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> graph[N];
vector<int> vis(N, 0), color(N, -1);
int n, m, l;

void reset() {
    for(int i = 0; i <= n; i++) {
        graph[i].clear();
        vis[i] = 0;
        color[i] = -1;
    }
}

void dfs(int node) {
    vis[node] = 1;
    for(auto child : graph[node]) {
        if(!vis[child]) dfs(child);
    }
}

bool isBipartite(int node) {
    for(auto child : graph[node]) {
        if(color[child] == -1) {
            color[child] = !color[node];
            if(isBipartite(child) == false) return false;
        } else if(color[child] == color[node]) return false;
    }
    return true;
}

void solve() {
    while(1) {
        cin>>n;
        if(n == 0) break;
        reset();
        cin>>m;
        for(int i = 0; i < m; i++) {
            int u, v; cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        color[0] = 1;
        if(isBipartite(0)) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 