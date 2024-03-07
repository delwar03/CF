#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
int n, m;
const int INF = 1e15 + 10;
vector<int> g[N], level, par;

void reset() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
    level.assign(n + 1, -1);
    par.assign(n + 1, -1);
}

void dfs(int node, int l = 0) {
    if(level[node] != -1) return;
    level[node] = l;
    for(auto child : g[node]) {
        dfs(child, l + 1);
        par[child] = node;
    }
}

int findAncestor(int u, int v) {
    if(level[u] < level[v]) swap(u, v);
    while(level[u] != level[v]) u = par[u];
    while(u != v) {
        u = par[u];
        v = par[v];
    }
    return u;
}

void solve() {
    cin>>n;
    reset();
    for(int i = 1; i <= n; i++) {
        cin>>m;
        for(int j = 0; j < m; j++) {
            int u; cin>>u;
            g[i].push_back(u);
        }
    }
    dfs(1);
    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        cout<<findAncestor(u, v)<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": "<<endl;;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 