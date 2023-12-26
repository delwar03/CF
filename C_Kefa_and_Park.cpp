#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
int n, m, ans = 0;
vector<int> g[N], cat(N);

void dfs(int u, int p, int c) {
    if(c > m) return;

    int child = 0;
    for(auto v : g[u]) {
        if(v == p) continue;

        if(cat[u]) dfs(v, u, c + cat[v]);
        else dfs(v, u, cat[v]);
        child++;
    }
    if(child == 0) {
        ans++;
        return;
    }
    
}


void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>cat[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, cat[1]);

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