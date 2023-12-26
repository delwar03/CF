#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> g[N];
vector<int> dp(N);

void dfs(int u, int p, int i) {
    for(auto it : g[u]) {
        int v = it[0];
        int j = it[1];
        if(v == p) continue;
        dp[v] = dp[u] + (j < i); 
        dfs(v, u, j);
    }
}

void solve() {
    int n; cin>>n;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
    }
    dp.assign(n + 1, 0);

    for(int i = 1; i < n; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    dfs(1, -1, N);
    int ans = *max_element(dp.begin(), dp.end());
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