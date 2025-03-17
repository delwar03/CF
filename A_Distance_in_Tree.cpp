#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> down(n + 1, vector<int>(k + 1, 0)), up(n + 1, vector<int>(k + 1, 0));

    function<void(int, int)> dfs_down = [&] (int u, int p) {
        down[u][0] = 1;
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs_down(v, u);
                for(int j = 1; j <= k; j++) {
                    down[u][j] += down[v][j - 1];
                }
            }
        }
    };

    function<void(int, int)> dfs_up = [&] (int u, int p) {
        vector<vector<int>> pref, suff;
        up[u][0] = 1;
        for(auto v : g[u]) {
            if(v ^ p) {
                vector<int> tmp;
                for(int j = 0; j <= k; j++) {
                    tmp.push_back(down[v][j]);
                }
                pref.push_back(tmp);
                suff.push_back(tmp);
            }
        }

        int childNo = pref.size();

        for(int i = 1; i < childNo; i++) {
            for(int j = 0; j <= k; j++) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        for(int i = childNo - 2; i >= 0; i--) {
            for(int j = 0; j <= k; j++) {
                suff[i][j] += suff[i + 1][j];
            }
        }

        // dp[v][k] += dp[siblings][k - 2]
        int ind = 0;
        for(auto v : g[u]) {
            if(v ^ p) {
                for(int j = 2; j <= k; j++) {
                    int left = (ind - 1 >= 0 ? pref[ind - 1][j - 2] : 0);
                    int right = (ind + 1 < childNo ? suff[ind + 1][j - 2] : 0);
                    up[v][j] += left + right;
                }
                ind++;
            }
        }

        // dp[v][k] += dp[u][k - 1]
        for(auto v : g[u]) {
            if(v ^ p) {
                for(int j = 1; j <= k; j++) {
                    up[v][j] += up[u][j - 1];
                }
                dfs_up(v, u);
            }
        }
    };

    dfs_down(1, 0);
    dfs_up(1, 0);

    long long ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += up[i][k];
        ans += down[i][k];
    }
    cout<<ans / 2<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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