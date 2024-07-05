#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
vector<int> g[N];
vector<int> dist(N, INF);

void solve() {
    int n, m; cin>>n>>m;
    map<int, set<int>> track;
    map<int, int> color;
    map<vector<int>, int> col_of_edge;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v, c; cin>>u>>v>>c;
        if(color.find(u) == color.end()) track[c].insert(u), color[u] = c;
        if(color.find(v) == color.end()) track[c].insert(v), color[v] = c;
        col_of_edge[{u, v}] = c;
        edges.push_back({u, v});
    }
    set<int> to_be_erased;

    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int c = col_of_edge[{u, v}];
        for(auto val : track) {
            int next_col = val.first;
            auto st = val.second;
            if(next_col == c || (st.find(u) == st.end() && st.find(v) == st.end())) continue;
            g[c].push_back(next_col);
            g[next_col].push_back(c);
            to_be_erased.insert(c);
            to_be_erased.insert(next_col);
        }
    }
    int startt, endd; cin>>startt>>endd;
    if(startt == endd) {cout<<0<<endl; return; }
    startt = color[startt]; endd = color[endd];
    // cerr<<startt<<" "<<endd<<endl;

    auto bfs = [&] (int src) {
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(q.size()) {
            int node = q.front();
            q.pop();
            for(auto child : g[node]) {
                if(dist[node] + 1 < dist[child]) {
                    dist[child] = dist[node] + 1;
                    q.push(child);
                }
            }
        }
    };

    bfs(startt);
    cout<<dist[endd] + 1<<endl;
    for(auto it : to_be_erased) {
        g[it].clear();
    }
    dist.assign(N, INF);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 