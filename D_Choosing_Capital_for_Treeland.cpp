#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<int>> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }

    vector<int> down(n + 1, 0), up(n + 1, 0);


    function<void(int, int)> dfs_down = [&] (int u, int p) {
        
        for(auto it : g[u]) {
            int v = it[0];
            int wt = it[1];
            if(v ^ p) {
                dfs_down(v, u);
                down[u] += wt + down[v];
            }
        }
    };

    function<void(int, int)> dfs_up = [&] (int u, int p) {

        int pref = 0;
        for(auto it : g[u]) {
            int v = it[0];
            int wt = it[1];
            if(v ^ p) {
                up[v] += pref;
                pref += wt + down[v];
            }
        }

        reverse(g[u].begin(), g[u].end());

        int suff = 0;
        for(auto it : g[u]) {
            int v = it[0];
            int wt = it[1];
            if(v ^ p) {
                up[v] += suff;
                suff += wt + down[v];
            }
        }

        reverse(g[u].begin(), g[u].end());

        for(auto it : g[u]) {
            int v = it[0];
            int wt = it[1];
            if(v ^ p) {
                up[v] += !wt + up[u];
                dfs_up(v, u);
            }
        }
    };

    dfs_down(1, 0);
    dfs_up(1, 0);

    // for(int i = 1; i <= n; i++) cerr<<down[i]<<" "; cerr<<endl;
    // for(int i = 1; i <= n; i++) cerr<<up[i]<<" "; cerr<<endl;

    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++) {
        mp[down[i] + up[i]].push_back(i);
    }

    for(auto it : mp) {
        cout<<it.first<<endl;
        for(auto u : it.second) cout<<u<<" "; cout<<endl;
        break;
    }
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