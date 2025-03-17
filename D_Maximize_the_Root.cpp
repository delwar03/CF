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
    vector<int> val(n + 1), g[n + 1];
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 2; i <= n; i++) {
        int p; cin>>p;
        g[p].push_back(i);
    }

    function<int(int)> dfs = [&] (int u) {
        if(g[u].empty()) return val[u];
        int mn = INF;
        for(auto v : g[u]) {
            mn = min(mn, dfs(v));
        }

        if(u == 1 || val[u] >= mn) {
            return mn;
        } else {
            return val[u] + (mn - val[u]) / 2;
        }
    };

    int mn = dfs(1);

    cout<<val[1] + mn<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
