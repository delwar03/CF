#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> graph[N];
vector<int> vis(N, 0), color(N, -1);
int n, m, mx, mxNode;

void reset() {
    for(int i = 0; i <= n; i++) {
        graph[i].clear();
        vis[i] = 0;
        color[i] = -1;
    }
    mx = -1;
    mxNode = -1;
}

void solve() {
    cin>>n>>m;
    reset();
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<int> indegree(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        for(auto child : graph[i]) indegree[child]++;
    }
    vector<int> topo;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) pq.push(i);
    }
    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();
        topo.push_back(node);
        for(auto child : graph[node]) {
            indegree[child]--;
            if(indegree[child] == 0) pq.push(child);
        }
    }
    if(topo.size() == n) {
        for(auto it : topo) cout<<it<<" "; cout<<endl;
    } else {
        cout<<"Sandro fails."<<endl;
    }
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