#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> g[N];
vector<int> vis(N, 0);
int n, m, l;

void reset() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
    }
}

void dfs(int node) {
    vis[node] = 1;
    for(auto child : g[node]) {
        if(!vis[child]) dfs(child);
    }
}

void solve() {
    cin>>n>>m>>l;
    reset();
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        u--; v--;
        g[u].push_back(v);
    }
    for(int i = 0; i < l; i++) {
        int x; cin>>x;
        x--;
        dfs(x);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        // cout<<vis[i]<<" ";
        ans += vis[i];
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
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 