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
    int n, k; cin>>n>>k;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dp(n + 1), val;

    function<int(int, int)> dfs = [&] (int u, int p) {
        int mxChild = -1, mxVal = 1;
        for(auto v : g[u]) {
            if(v ^ p) {
                int cur = dfs(v, u);
                if(1 + cur > mxVal) {
                    mxVal = 1 + cur;
                    mxChild = v;
                }
            }
        }
        for(auto v : g[u]) {
            if(v ^ p) {
                if(mxChild ^ v) {
                    val.push_back(dp[v]);
                }
            }
        }

        return dp[u] = mxVal;
    };

    val.push_back(dfs(1, 0));
    sort(val.rbegin(), val.rend());
    val.resize(k);

    // for(auto it : val) cerr<<it<<" "; cerr<<endl;
    // for(int i = 1; i <= n; i++) cerr<<dp[i]<<" "; cerr<<endl;

    int r = 0, w = 0, tot = n, ans = -INF;
    for(int i = 0; i < k; i++) {
        r++;
        tot -= val[i];
        int b = min(tot, n / 2);
        w = n - r - b;
        ans = max(ans, w * (r - b));
    }

    cout<<ans<<endl;
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