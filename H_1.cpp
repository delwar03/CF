#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

vector<int> adj[N], adj_t[N];
vector<int> vis(N), color(N);
vector<int> topo;

void dfs(int u) {
    vis[u] = 1;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    topo.push_back(u);
}

void dfs(int u, int col) {
    vis[u] = 1;
    color[u] = col;
    for(auto v : adj_t[u]) {
        if(!vis[v]) {
            dfs(v, col);
        }
    }
}

void reset(int n) {
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        adj_t[i].clear();
        vis[i] = 0;
        color[i] = -1;
    }
    topo.clear();
}

void solve() {
    int n; cin>>n;
    reset(2 * n + 1);
    int grid[3][n];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin>>grid[i][j];
        }
    }

    auto add_edge = [&] (int u, int v) {
        adj[u].push_back(v);
        adj_t[v].push_back(u);
    };

    auto f = [&] (int a) {
        if(a <= n) return a + n;
        return a - n;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            int a = grid[j][i];
            if(a < 0) a = -a + n;
            for(int k = j + 1; k < 3; k++) {
                int b = grid[k][i];
                if(b < 0) b = -b + n;
                add_edge(f(a), b);
                add_edge(f(b), a);
            }
        }
    }

    for(int i = 1; i <= 2 * n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    vis.assign(2 * n + 1, 0);
    reverse(topo.begin(), topo.end());
    int c = 0;
    for(auto it : topo) {
        if(!vis[it]) {
            dfs(it, c++);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(color[i] == color[i + n]) {
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