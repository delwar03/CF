#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
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
    int n, k; cin>>n>>k;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    int mx = -1, ans = 0, val = 0;
    for(int i = 0; i < min(n, k); i++) {
        val += a[i];
        mx = max(mx, b[i]);
        ans = max(ans, val + (k - i - 1) * mx);
    }
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