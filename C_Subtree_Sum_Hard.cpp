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

void solve() {
    int n; cin>>n;
    vector<int> g[n + 1], val(n + 1);
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> siz(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        siz[u] = val[u];
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u);
                siz[u] += siz[v];
            }
        }
    };

    dfs(1, 0);

    for(int i = 1; i <= n; i++) cout<<siz[i]<<" \n"[i == n];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}