#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> g[N];
vector<int> color(N, -1), vis(N, 0), ache(N, 0), col(2, 0);

int n, m, mx, mxNode, cnt0 = 0, cnt1 = 0;

void reset() {
    for(int i = 0; i < N; i++) {
        g[i].clear();
        color[i] = -1;
        vis[i] = 0;
        ache[i] = 0;
    }
    mx = -1;
    mxNode = -1;
    cnt0 = 0;
    cnt1 = 0;
}

bool dfs(int node, int c = 0) {
    vis[node] = 1;
    for(auto child : g[node]) {
        if(!vis[child]) dfs(child, 1 ^ c);
    }
    col[c]++;
}

void solve() {
    cin>>n;
    reset();

    for(int i = 0; i < n; i++) {
        int u, v; cin>>u>>v;
        // u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        ache[u] = 1;
    }

    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(ache[i] == 1 && vis[i] == 0) {
            col[0] = col[1] = 0;
            dfs(i);
            ans += max(col[0], col[1]);
            // cout<<col.size()<<endl;
            // for(auto it : col) cout<<it<<" "; cout<<endl;
        }
    }
    cout<<ans<<endl;
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