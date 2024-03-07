#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
int n, m;
vector<int> g[N];

vector<int> getTopoSort() {
    vector<int> indegree(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        for(auto child : g[i]) {
            indegree[child]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()) {
        if(q.size() > 1) return {};
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto child : g[node]) {
            indegree[child]--;
            if(indegree[child] == 0) {
                q.push(child);
            }
        }
    }
    return topo;
}

void solve() {
    cin>>n>>m;
    set<int> nodes;
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        nodes.insert(u);
        nodes.insert(v);
    }
    vector<int> topo = getTopoSort();
    if(topo.size() == nodes.size()) {
        cout<<"Yes"<<endl;
        vector<int> ans(n);
        int val = 1;
        for(auto it : topo) {
            ans[it - 1] = val++;
        }
        for(int i = 0; i < n; i++) {
            if(val > n) break;
            if(ans[i] == 0) ans[i] = val++;
        }
        for(auto it : ans) cout<<it<<" "; cout<<endl;
    }
    else cout<<"No"<<endl;
    for(int i = 0; i <= n; i++) g[i].clear();
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
}
 
/*
i/p:  
o/p: 
*/ 