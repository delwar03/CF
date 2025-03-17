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
    set<int> g[n + 1];
    vector<int> deg(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        deg[u] += 1;
        deg[v] += 1;
    }

    // for(int i = 1; i <= n; i++) cerr<<deg[i]<<" "; cerr<<endl;
    
    vector<pii> vv;
    for(int i = 1; i <= n; i++) vv.push_back({deg[i], i});

    sort(vv.rbegin(), vv.rend());

    int mx = 1;

    for(int u = 1; u <= n; u++) {
        for(int j = 0; j < min(n, sz(g[u]) + 5); j++) {
            auto [d2, v] = vv[j];
            if(v == u) continue;
            mx = max(mx, deg[u] + d2 + (g[u].count(v) ? -1 : 0));
        }
    }

    cout<<mx - 1<<endl;
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