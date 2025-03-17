#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

int down[50001][501]; // no. of k len paths from u = dp[u][k]
int up[50001][501]; // no. of k len paths from u = dp[u][k]

void solve() {
    int n, k; cin>>n>>k;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i <= n; i++) {
        down[i][0] = up[i][0] = 1;
    }

    function<void(int, int)> dfs_down = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs_down(v, u);
                for(int i = 1; i <= k; i++) {
                    down[u][i] += down[v][i - 1];
                }
            }
        }
    };

    function<void(int, int)> dfs_up = [&] (int u, int p) {

        vector<vector<int>> pref, suff;

        for(auto v : g[u]) {
            if(v ^ p) {
                vector<int> tmp;
                for(int i = 0; i <= k; i++) {
                    tmp.push_back(down[v][i]);
                }
                pref.push_back(tmp);
                suff.push_back(tmp);
            }
        }

        int ct = pref.size();

        for(int j = 0; j <= k; j++) {
            for(int i = 1; i < ct; i++) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        for(int j = 0; j <= k; j++) {
            for(int i = ct - 2; i >= 0; i--) {
                suff[i][j] += suff[i + 1][j];
            }
        }

        int ind = 0;

        for(auto v : g[u]) {
            if(v ^ p) {
                for(int j = 1; j <= k; j++) {
                    int left = ind - 1 >= 0 && j - 2 >= 0 ? pref[ind - 1][j - 2] : 0;
                    int right = ind + 1 < ct && j - 2 >= 0 ? suff[ind + 1][j - 2] : 0;

                    up[v][j] += left + right;
                    up[v][j] += up[u][j - 1];
                }
                dfs_up(v, u);
                ind++;
            }
        }
    };

    dfs_down(1, 0);
    dfs_up(1, 0);

    long long ans = 0;

    // for(int i = 1; i <= n; i++) cout<<down[i][k]<<" "; cout<<endl;
    // for(int i = 1; i <= n; i++) cout<<up[i][k]<<" "; cout<<endl;

    for(int i = 1; i <= n; i++) {
        ans += down[i][k] + up[i][k];
    }

    cout<<ans / 2<<endl;
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