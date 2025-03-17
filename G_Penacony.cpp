#include <bits/stdc++.h>
#define int long long
#define endl '\n'
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
    int n, m; cin>>n>>m;
    vector<int> f(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        int x = rng();
        f[u] ^= x;
        f[v] ^= x;
    }

    for(int i = 1; i <= n; i++) {
        f[i] ^= f[i - 1];
    }

    map<int, int> mp;
    int ans = n;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, n - ++mp[f[i]]);
    }

    cout<<ans<<endl;
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
