#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, m, k, s, t;
vector<vector<int>> graph[N], revGraph[N];
vector<int> dist(N, INF);

void dijkstra(int src, vector<vector<int>> graph[]) {
    dist[src] = 0;
    set<vector<int>> st;
    st.insert({0, src});
    while(st.size()) {
        int node = (*st.begin())[1];
        int dst = (*st.begin())[0];
        st.erase(st.begin());

        for(auto it : graph[node]) {
            int child = it[0];
            int wt = it[1];
            if(dst + wt < dist[child]) {
                dist[child] = dst + wt;
                st.insert({dist[child], child});
            }
        }
    }
}

void reset() {
    for(int i = 0; i <= n; i++) {
        graph[i].clear();
        revGraph[i].clear();
        dist[i] = INF;
    }
}

void solve() {

    cin>>n>>m>>k>>s>>t;
    s--; t--;
    reset();
    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        u--; v--;
        graph[u].push_back({v, wt});
        revGraph[v].push_back({u, wt});
    }
    dijkstra(s, graph);
    auto dis1 = dist;
    dist.assign(N, INF);
    dijkstra(t, revGraph);
    auto dis2 = dist;
    dist.assign(N, INF);

    int ans = INF;

    for(int i = 0; i < k; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        u--; v--;
        // graph[u].push_back({v, wt});
        // graph[v].push_back({u, wt});
        int x = dis1[u] + wt + dis2[v];
        int y = dis2[u] + wt + dis1[v];
        ans = min(ans, min(x, y));
        ans = min(ans, dis1[t]);
    }
    // dijkstra(s);
    if(ans == INF) cout<<"-1"<<endl;
    else cout<<ans<<endl;
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
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 