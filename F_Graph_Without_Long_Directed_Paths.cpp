#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
int n, m, ans = 0;
vector<int> g[N], vis(N), col(N, -1);
vector<vector<int>> edges;
int cyc = 1;

bool dfs(int u) {
    for(auto v : g[u]) {
        if(col[v] == -1) {
            col[v] = !col[u];
            if(dfs(v) == false) return false;
        } else if(col[v] == col[u]) return false;
    }
    return true;
}


void solve() {
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        edges.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    col[1] = 1;
    if(dfs(1) == false) cout<<"NO\n";
    else {
        cout<<"YES\n";
        for(auto it : edges) cout<<col[it[0]];
        cout<<endl;
    }
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