#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

vector<int> g[N];
vector<vector<int>> bridges;
int tin[N], low[N], sz[N];
int timer = 1;

void dfs(int u, int p = -1) {
    sz[u] = 1;
    tin[u] = low[u] = timer++;
    for(auto v : g[u]) {
        if(v ^ p) {
            if(!sz[v]) {
                dfs(v, u);
                sz[u] += sz[v];
            }
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) {
                bridges.push_back({u, v});
            }
        }
    }
}

void reset(int n) {
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        tin[i] = low[i] = sz[i] = 0;
    }
    bridges.clear();
}

void solve() {
    int n, m; cin>>n>>m;
    reset(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int ans = n * (n - 1) / 2;
    int mx = 0;
    for(auto it : bridges) {
        int v = it[1];
        mx = max(mx, sz[v] * (n - sz[v]));
    }
    ans -= mx;
    cout<<ans<<endl;
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