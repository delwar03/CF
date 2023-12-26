#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
int n, k, mx, nd, cnt;
vector<int> graph[N], marked(N), vis(N);

void reset() {
    for(int i = 0; i <= n; i++) {
        marked[i] = vis[i] = 0;
        graph[i].clear();
    }
    mx = 0, nd = 0, cnt = 0;
}

void dfs(int node) {
    vis[node] = 1;
    for(auto child : graph[node]) {
        if(!vis[child]) {
            cnt++;
            if(marked[child]) {
                if(cnt > mx) {nd = child; mx = cnt;}
            }
            dfs(child);
            cnt--;
        }
    }
}

void solve() {
    cin>>n>>k;
    reset();
    vector<int> v(k);
    for(auto &x : v) {cin>>x; marked[x] = 1; }
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    nd = v[0];
    dfs(nd);
    vis.assign(n + 1, 0);
    mx = 0; cnt = 0;
    dfs(nd);
    int ans = (mx + 1) / 2;
    cout<<ans<<endl;
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
}
 
/*
i/p:  
o/p: 
*/ 