#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int n, m, mx, mxNode;

void reset() {
    // for(int i = 0; i <= n; i++) {
    //     graph[i].clear();
    //     vis[i] = 0;
    //     color[i] = -1;
    //     dist[i] = INF;
    // }
    mx = -1;
    mxNode = -1;
}

void dijkstra(int src, vector<vector<int>> g[], vector<int>& dist, vector<int>& vis) {
    dist[src] = 0;
    set<vector<int>> st;
    st.insert({0, src});
    while(st.size()) {
        int node = (*st.begin())[1];
        int dst = (*st.begin())[0];
        st.erase(st.begin());
        if(vis[node]) continue;
        vis[node] = 1;
        
        for(auto it : g[node]) {
            int child = it[0];
            int wt = it[1];
            if(wt + dst < dist[child]) {
                dist[child] = wt + dst;
                st.insert({dist[child], child});
            }
        }
    }
}

void solve() {
    cin>>n>>m;
    reset();
    vector<vector<int>> g1[n + 1], g2[n + 1];
    vector<int> dist1(n + 1, INF), dist2(n + 1, INF), vis1(n + 1, 0), vis2(n + 1, 0);
    vector<vector<int>> edges;

    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g1[u].push_back({v, wt});
        g2[v].push_back({u, wt});
        edges.push_back({u, v, wt});
    }
    dijkstra(1, g1, dist1, vis1);
    dijkstra(n, g2, dist2, vis2);
    // for(auto it : dist1) cout<<it<<" "; cout<<endl;
    // for(auto it : dist2) cout<<it<<" "; cout<<endl;
    
    int ans = INF;
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        ans = min(ans, dist1[u] + wt / 2 + dist2[v]);
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
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 