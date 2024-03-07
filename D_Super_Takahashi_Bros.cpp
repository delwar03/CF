#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> graph[N];
vector<int> dist(N, INF);

void dijkstra(int src) {
    dist[src] = 0;
    set<vector<int>> st;
    st.insert({0, src});
    while(st.size()) {
        int node = (*st.begin())[1];
        st.erase(st.begin());
        for(auto it : graph[node]) {
            int child = it[0];
            int wt = it[1];
            if(dist[node] + wt < dist[child]) {
                dist[child] = dist[node] + wt;
                st.insert({dist[node], child});
            } 
        }
    }
}

void solve() {
    int n; cin>>n;
    for(int i = 1; i <= n - 1; i++) {
        int a, b, x; cin>>a>>b>>x;
        graph[i].push_back({i + 1, a});
        graph[i].push_back({x, b});
    }
    dijkstra(1);

    cout<<dist[n]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 