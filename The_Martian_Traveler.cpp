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
    int n, m, k; cin >> n >> m >> k;
    vector<int> g[n + 1], gT[n + 1], id(n + 1), ord;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gT[v].push_back(u);
    }

    vector<vector<int>> comp;
    vector<int> vis(n + 1);

    function<void(int, int)> dfs = [&] (int u, int f) {
        vis[u] = 1;
        for(auto v : (!f ? g[u] : gT[u])) if(!vis[v]) {
            dfs(v, f);
        }
        if(!f) ord.push_back(u);
        else comp.back().push_back(u), id[u] = f - 1;
    };

    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i, 0);
    reverse(ord.begin(), ord.end());
    vis = vector<int>(n + 1, 0);
    int cur = 0;
    for(int i : ord) if(!vis[i]) {
        comp.push_back({});
        dfs(i, ++cur);
    }
    // sort(comp.begin(), comp.end(), [&] (const auto& a, const auto& b) {
    //     return a.size() > b.size();
    // });

    vector<int> tr[cur + 1];
    for(int u = 1; u <= n; u++) {
        for(int v : g[u]) if(id[u] ^ id[v]) {
            tr[id[u]].push_back(id[v]);
        }
        sort(tr[id[u]].begin(), tr[id[u]].end());
        tr[id[u]].erase(unique(tr[id[u]].begin(), tr[id[u]].end()), tr[id[u]].end());
        sort(tr[id[u]].begin(), tr[id[u]].end(), [&] (const auto& a, const auto& b) {
            return sz(comp[a]) > sz(comp[b]);
        });
    }

    int mx = 0;

    for(int i = 0; i < cur; i++) {
        int sm = sz(comp[i]);
        for(int j = 0; j < min(k - 1, sz(tr[i])); j++) {
            sm += sz(comp[tr[i][j]]);
        }
        mx = max(mx, sm);
    }

    cout << mx << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}