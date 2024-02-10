#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> graph[N];
vector<int> vis(N, 0), color(N, -1);
int n, mx, mxNode;

void reset() {
    for(int i = 0; i <= n; i++) {
        graph[i].clear();
        vis[i] = 0;
        color[i] = -1;
    }
    mx = -1;
    mxNode = -1;
}

void bfs(int src) {
    vis[src] = 1;
    queue<vector<int>> q;
    q.push({src, 0});
    while(!q.empty()) {
        int node = q.front()[0];
        int dst = q.front()[1];
        q.pop();
        if(dst > mx) {
            mx = dst;
            mxNode = node;
        }
        for(auto it : graph[node]) {
            int child = it[0];
            int wt = it[1];
            if(!vis[child]) {
                vis[child] = 1;
                q.push({child, dst + wt});
            }
        }
    }
}

void solve() {
    cin>>n;
    reset();
    for(int i = 0; i < n - 1; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    bfs(0);
    vis.assign(n + 1, 0);
    bfs(mxNode);
    cout<<mx<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 