#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> g[n];

    for(int i = 0; i < m; i++) {
        int a, b, x, y; cin>>a>>b>>x>>y;
        a--; b--;
        g[a].push_back({b, x, y});
        g[b].push_back({a, -x, -y});
    }
    vector<int> x(n), y(n), que(1, 0), vis(n, 0);
    vis[0] = 1;
    
    for(int i = 0; i < que.size(); i++) {
        for(auto p : g[que[i]]) {
            int v = p[0];
            int nx = x[que[i]] + p[1];
            int ny = y[que[i]] + p[2];
            if(!vis[v]) {
                x[v] = nx;
                y[v] = ny;
                vis[v] = 1;
                que.push_back(v);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(!vis[i]) cout<<"undecidable"<<endl;
        else cout<<x[i]<<" "<<y[i]<<endl;
    }
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
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 