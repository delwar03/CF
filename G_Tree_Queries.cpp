#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    int n, q; cin >> n >> q;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> mn(n + 1, INF);
    int prv = 0, t, u; cin >> t >> u;
    u = 1 + (u + prv) % n;
    q--;

    function<void(int, int)> dfs = [&] (int u, int p) {
        mn[u] = min(u, mn[p]);
        for(auto v : g[u]) if(v ^ p) {
            dfs(v, u);
        }
    };

    dfs(u, 0);

    int mnAns = n;
    
    while(q--) {
        cin >> t >> u;
        u = 1 + (u + prv) % n;
        if(t == 1) {
            mnAns = min(mnAns, mn[u]);
        } else {
            cout << (prv = min(mnAns, mn[u])) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}