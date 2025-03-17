#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int dp[N][2];

void solve() {
    int n; cin>>n;
    vector<int> par(n), color(n), g[n];
    for(int i = 1; i < n; i++) {
        cin>>par[i];
        g[par[i]].push_back(i);
        g[i].push_back(par[i]);
    }
    for(int i = 0; i < n; i++) cin>>color[i];

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u);
            }
        }

        if(color[u] == 1) { // black
            dp[u][0] = 0;
            dp[u][1] = 1;

            for(auto v : g[u]) {
                if(v ^ p) {
                    dp[u][1] *= (dp[v][0] + dp[v][1]);
                    dp[u][1] %= mod;
                }
            }
        } else { // white
            dp[u][0] = 1;
            dp[u][1] = 0;

            int k = 0;
            vector<int> pref, suff;
            for(auto v : g[u]) {
                if(v ^ p) {
                    pref.push_back(dp[v][0] + dp[v][1]);
                    suff.push_back(dp[v][0] + dp[v][1]);
                    k++;
                }
            }

            if(k == 0) return;

            for(int i = 1; i < k; i++) {pref[i] *= pref[i - 1]; pref[i] %= mod;}
            for(int i = k - 2; i >= 0; i--) {suff[i] *= suff[i + 1]; suff[i] %= mod;}

            dp[u][0] = pref.back();

            int i = 0;

            int prod = pref.back();

            for(auto v : g[u]) {
                if(v ^ p) {
                    int left = (i == 0 ? 1 :pref[i - 1]);
                    int right = (i == k - 1 ? 1 : suff[i + 1]);

                    dp[u][1] += (((left * dp[v][1]) % mod) * right) % mod;
                    dp[u][1] %= mod;

                    i++;
                }
            }
        }
    };

    dfs(0, -1);

    cout<<dp[0][1]<<endl;
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