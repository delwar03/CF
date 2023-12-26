#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
int n, m, ans = 0;
vector<int> g[N], vis(N);
int cyc = 1;

void dfs(int u) {
    vis[u] = 1;
    if(g[u].size() != 2) cyc = 0;
    for(auto v : g[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}


void solve() {
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cyc = 1;
            dfs(i);
            ans += cyc;
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
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 