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
    int n, m; cin>>n>>m;
    vector<string> grid(n);
    vector<int> val(m);
    for(auto &x : grid) cin>>x;
    for(auto &x : val) cin>>x;

    auto get = [&] (int i, int j) {
        return i * m + j;
    };

    vector<int> col[m], g[n * m], gT[n * m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(grid[i][j] == '#') {
            col[j].push_back(i);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(grid[i][j] == '#') {
            if(i - 1 >= 0 && grid[i - 1][j] == '#') g[get(i, j)].push_back(get(i - 1, j));
            int id = upper_bound(col[j].begin(), col[j].end(), i) - col[j].begin();
            if(id < sz(col[j])) g[get(i, j)].push_back(get(col[j][id], j));
            id = j - 1 >= 0 ? lower_bound(col[j - 1].begin(), col[j - 1].end(), i) - col[j - 1].begin() : INF;
            if(j - 1 >= 0 && id < sz(col[j - 1])) g[get(i, j)].push_back(get(col[j - 1][id], j - 1));
            id = j + 1 < m ? lower_bound(col[j + 1].begin(), col[j + 1].end(), i) - col[j + 1].begin() : INF;
            if(j + 1 < m && id < sz(col[j + 1])) g[get(i, j)].push_back(get(col[j + 1][id], j + 1));
        }
    }

    for(int u = 0; u < n * m; u++) {
        for(int v : g[u]) {
            gT[v].push_back(u);
        }
    }

    vector<int> vis(n * m), id(n * m), comp[n * m], ord;

    function<void(int, int)> dfs = [&] (int u, int f) {
        vis[u] = 1;
        for(auto v : (!f ? g[u] : gT[u])) if(!vis[v]) {
            dfs(v, f);
        }
        if(!f) ord.push_back(u);
        else comp[f - 1].push_back(u), id[u] = f - 1;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(grid[i][j] == '#' && !vis[get(i, j)]) {
            dfs(get(i, j), 0);
        }
    }
    reverse(ord.begin(), ord.end());

    vis = vector<int>(n * m, 0);
    int ct = 0;
    for(auto i : ord) if(!vis[i]) {
        dfs(i, ++ct);
    }

    vector<int> ng[ct];
    for(int i = 0; i < ct; i++) {
        for(auto u : comp[i]) {
            for(auto v : g[u]) if(id[v] ^ i) {
                ng[i].push_back(id[v]);
            }
        }
        sort(ng[i].begin(), ng[i].end());
        ng[i].erase(unique(ng[i].begin(), ng[i].end()), ng[i].end());
    }

    vector<int> mn(ct, INF), mx(ct, -INF);

    for(int j = 0; j < m; j++) {
        for(int i : col[j]) {
            int u = id[get(i, j)];
            mn[u] = min(mn[u], j);
            mx[u] = max(mx[u], j);
        }
    }

    for(int i = 0; i < ct; i++) {
        for(int j : ng[i]) {
            mn[j] = min(mn[j], mn[i]);
            mx[j] = max(mx[j], mx[i]);
        }
    }

    vector<pii> segs;
    for(int j = 0; j < m; j++) if(val[j]) {
        int u = id[get(col[j].end()[-val[j]], j)];
        segs.push_back({mx[u], mn[u]});
    }

    sort(segs.begin(), segs.end());

    // for(auto [r, l] : segs) cerr<<l<<" "<<r<<endl;
    
    int ans = 0, last = -1;
    for(auto [r, l] : segs) if(l > last) {
        ans++, last = r;
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}