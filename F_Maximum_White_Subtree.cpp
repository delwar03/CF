#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n; cin>>n;
    vector<int> col(n + 1), g[n + 1];
    for(int i = 1; i <= n; i++) {
        cin>>col[i];
        if(col[i] == 0) col[i] = -1;
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> down(n + 1, 0), up(n + 1, 0);

    function<void(int, int)> dfs_down = [&] (int u, int p) {
        down[u] = col[u];
        for(int v : g[u]) {
            if(v ^ p) {
                dfs_down(v, u);
                down[u] = max(down[u], down[u] + down[v]);
            }
        }
    };

    function<void(int, int)> dfs_up = [&] (int u, int p) {
        int pref = 0;
        for(int v : g[u]) {
            if(v ^ p) {
                up[v] += pref;
                if(down[v] > 0) pref += down[v];
            }
        }

        reverse(g[u].begin(), g[u].end());

        int suff = 0;

        for(int v : g[u]) {
            if(v ^ p) {
                up[v] += suff;
                if(down[v] > 0) suff += down[v];
            }
        }

        reverse(g[u].begin(), g[u].end());

        for(int v : g[u]) {
            if(v ^ p) {
                up[v] += up[u];
                up[v] += col[u];
                if(up[v] < 0) up[v] = 0;
                dfs_up(v, u);
            }
        }
    };

    dfs_down(1, 0);
    dfs_up(1, 0);

    for(int i = 1; i <= n; i++) cout<<(down[i] + up[i])<<" "; cout<<endl;
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
