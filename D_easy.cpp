#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 60;
const int INF = 1e15 + 10;
vector<vector<int>> graph[N];
vector<int> vis(N, 0), color(N, -1), dist(N, INF), par(N, -1);
int n, m, mx, mxNode;
int x1, y1, x2, y2;
int mat[N][N];

vector<string> paths;

void reset() {
    for(int i = 0; i <= n; i++) {
        graph[i].clear();
        vis[i] = 0;
        color[i] = -1;
        dist[i] = INF;
    }
    mx = -1;
    mxNode = -1;
}

// void dijkstra(int src) {
//     dist[src] = 0;
//     multiset<vector<int>> st;
//     st.insert({0, src});
//     while(st.size()) {
//         int node = (*st.begin())[1];
//         int dst = (*st.begin())[0];
//         st.erase(st.begin());

//         for(auto it : graph[node]) {
//             int child = it[0];
//             int wt = it[1];
//             if(wt + dst < dist[child]) {
//                 dist[child] = wt + dst;
//                 st.insert({dist[child], child});
//                 par[child] = node;
//             }
//         }
//     }
// }

vector<vector<int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
}; // DURL

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void path(int i, int j) {
    if(!isValid(i, j)) return;
    for(int d = 0; d < 4; d++) {
        int nx = i + dir[d][0];
        int ny = j + dir[d][1];
        
    }
}

void solve() {
    cin>>n>>m;
    reset();
    cin>>x1>>y1>>x2>>y2;
    path(x1, y1);

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
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