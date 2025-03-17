#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, q;

void solve() {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    for(int i = 0; i < m; i++) {
        int u, v, w; cin>>u>>v>>w;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));

    while(q--) {
        int u, v; cin>>u>>v;
        if(dp[u][v] == INF) {
            cout<<"no path"<<endl;
        } else {
            cout<<dp[u][v]<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(cin>>n>>m>>q) {
        if(!n) break;
        if(c != 1) cout<<endl;
        cout<<"Case #"<<c++<<"\n";
        solve();
    }
}