#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n, m; cin>>n>>m;
    string s; cin>>s;
    vector<int> g[n];
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        --u; --v;
        g[u].push_back(v);
    }

    int ans = 0;
    vector<int> vis(n, 0);
    vector<vector<int>> dp(n, vector<int>(26, 0));

    function<bool(int)> dfs = [&] (int u) {
        vis[u] = 2;

        for(auto v : g[u]) {
            if(!vis[v]) {
                if(dfs(v)) return true;
            } else if(vis[v] == 2) {
                return true;
            }
            for(char ch = 'a'; ch <= 'z'; ch++) {
                dp[u][ch - 'a'] = max(dp[u][ch - 'a'], dp[v][ch - 'a']);
            }
        }

        dp[u][s[u] - 'a']++;
        for(int j = 0; j < 26; j++) {
            ans = max(ans, dp[u][j]);
        }

        vis[u] = 1;
        return false;
    };
    
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            if(dfs(i)) {
                cout<<-1<<endl;
                return;
            }
        }
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
