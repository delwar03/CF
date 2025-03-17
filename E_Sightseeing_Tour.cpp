#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[405][405];

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = (i == j ? 0 : INF);
        }
    }
    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        edges.push_back({u, v, wt});
        dp[u][v] = min(dp[u][v], wt);
        dp[v][u] = min(dp[v][u], wt);
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    vector<int> cur;

    function<int(int, int)> magic = [&] (int ind, int mask) {
        int sz = cur.size();
        if(__builtin_popcount(mask) == sz) {
            return dp[ind][n];
        }
        int res = INF;

        for(int i = 0; i < sz; i++) {
            if(mask & (1LL << i)) continue;
            int u = edges[cur[i]][0], v = edges[cur[i]][1], wt = edges[cur[i]][2];
            res = min(res, dp[ind][u] + wt + magic(v, mask | (1LL << i)));
            res = min(res, dp[ind][v] + wt + magic(u, mask | (1LL << i)));
        }
        return res;
    };

    int q; cin>>q;
    while(q--) {
        int k; cin>>k;
        cur.resize(k);
        for(auto &x : cur) {cin>>x; --x;}
        
        cout<<magic(1, 0)<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/