#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<pair<int, int>> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    vector<int> dp(n + 1), val;

    function<int(int, int)> dfs = [&] (int u, int p) {
        int mxChild = -1, mxVal = 0;
        for(auto it : g[u]) {
            int v = it.F, wt = it.S;
            if(v ^ p) {
                int cur = dfs(v, u);
                if(wt + cur > mxVal) {
                    mxVal = wt + cur;
                    mxChild = v;
                }
            }
        }

        for(auto it : g[u]) {
            int v = it.F, wt = it.S;
            if(v ^ p) {
                if(mxChild ^ v) {
                    val.push_back(wt + dp[v]);
                }
            }
        }
        return dp[u] = mxVal;
    };

    // val.push_back(dfs(1, 0));

    sort(val.rbegin(), val.rend());

    val.resize(n);
    for(auto it : val) cerr<<it<<" "; cerr<<endl;
    
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += 2 * val[i];
        cout<<cur<<endl;
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