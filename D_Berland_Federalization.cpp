#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int dp[405][405]; 
// dp[u][k] = min cuts required to make exactly k-size subtree rooted at u
int taken[405][405][405]; 
// taken[u][k][v] = required from u = k, taken from child v = taken[u][k][v]
// {u, sz, v}

void solve() {
    int n, k; cin>>n>>k;
    map<vector<int>, int> mp;
    vector<int> g[n + 1];
    for(int i = 1; i < n; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}] = mp[{v, u}] = i;
    }

    vector<int> par(n + 1, 0), ans;

    function<void(int, int)> dfs1 = [&] (int u, int p) {
        dp[u][0] = 1;
        dp[u][1] = 0;
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs1(v, u);
                par[v] = u;
                for (int sz = n; sz ; sz--) {
                    int tmp = INF;
                    for (int b = 0; b < sz; b++) {
                        int a = sz-b;
                        if (tmp > dp[u][a] + dp[v][b]) {
                            tmp = dp[u][a] + dp[v][b];
                            taken[u][sz][v] = b;
                        }
                    }
                    cerr<<"tmp: "<<tmp<<endl;
                    dp[u][sz] = tmp;
                }
            }
        }
    };

    function<void(int, int, int)> dfs2 = [&] (int u, int p, int sz) {
        for(auto v : g[u]) {
            if(v ^ p) {
                if(taken[u][sz][v]) {
                    dfs2(v, u, taken[u][sz][v]);
                } else {
                    ans.push_back(mp[{u, v}]);
                }
                sz -= taken[u][sz][v];
            }
        }
    };

    dfs1(1, 0);

    // for(int i = 1; i <= n; i++) cerr<<par[i]<<" \n"[i == n];

    for(int i = 1; i <= n; i++) {
        for(auto j : g[i]) {
            cerr<<taken[i][k][j]<<" ";
        } cerr<<endl;
    }

    int cur = dp[1][k], best = 1;
    for(int i = 2; i <= n; i++) {
        if(1 + dp[i][k] < cur) {
            cur = 1 + dp[i][k];
            best = i;
        }
    }

    if(cur == 0) {cout<<cur<<endl; return;}

    if(best != 1) ans.push_back(mp[{best, par[best]}]);

    
    dfs2(best, par[best], k);

    cerr<<"cur: "<<cur<<endl;

    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it<<" ";


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