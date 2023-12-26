#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> g[N];
vector<int> wt(N);

void dfs(int u, int p = -1, int i = 2) {
    for(auto it : g[u]) {
        int v = it[0];
        int j = it[1];// u - v
        if(v == p) continue;
        wt[j] = i;
        dfs(v, u, 5 - i);
    }
}

void solve() {
    int n; cin>>n;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
    }
    wt.assign(n + 1, 0);

    for(int i = 1; i < n; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    int x = 1;
    bool hobe = true;
    for(int i = 1; i <= n; i++) {
        hobe &= (g[i].size() <= 2);
        if(g[i].size() == 1) x = i;
    }
    if(!hobe) {cout<<"-1\n"; return; }
    dfs(x);
    for(int i = 1; i < n; i++) cout<<wt[i]<<" ";
    cout<<endl;
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