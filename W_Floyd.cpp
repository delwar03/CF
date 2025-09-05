#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 2147483647;
const int N = 16807;
const int MX = 105;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, s; cin>>n>>s;
    vector<pii> g[n];
    vector<vector<int>> dp(n, vector<int>(n));
    int cur = s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i ^ j) {
            dp[i][j] = cur % 1000;
            g[i].push_back({dp[i][j], j});
            cur = (1LL * cur * N) % mod;
        }
        sort(g[i].begin(), g[i].end());
    }

    if(n <= 200) {
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    } else {

        auto DJ = [&] (int src) {
            vector<int> cur[MX], &dd = dp[src];
            for(auto [w, v] : g[src]) {
                if(w < MX) {
                    cur[w].push_back(v);
                } else {
                    break;
                }
            }
            for(int i = 0; i < MX; i++) {
                while(sz(cur[i])) {
                    int u = cur[i].back(); cur[i].pop_back();
                    if(dd[u] < i) continue;
                    for(auto [w, v] : g[u]) {
                        if(w + i >= MX) break;
                        if(w + i < dd[v]) {
                            dd[v] = w + i;
                            cur[w + i].push_back(v);
                        }
                    }
                }
            }
        };

        for(int i = 0; i < n; i++) DJ(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = (1LL * ans * N + dp[i][j]) % mod;
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("floyd.in", "r")) {
        freopen("floyd.in", "r", stdin);
        freopen("floyd.out", "w", stdout);
    }

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}