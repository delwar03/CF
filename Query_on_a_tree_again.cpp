#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define lc (id << 1)
#define rc (id << 1 | 1)
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

int dp[31][N];

void solve() {
    int n, q; cin>>n>>q;
    vector<int> val(n + 1, 0), g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> sz(n + 1, 0), par(n + 1, 0), dep(n + 1, 0), hv(n + 1, 0), head(n + 1, 0), pos(n + 1, 0), lt(n + 1, 0);
    int idx = 1;

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dep[v] = 1 + dep[u];
                par[v] = u;
                dfs(v, u);
                sz[u] += sz[v];
                if(sz[v] > sz[hv[u]]) {
                    hv[u] = v;
                }
            }
        }
        sz[u]++;
    };

    function<void(int, int, int)> dfs2 = [&] (int u, int p, int hd) {

        head[u] = hd;
        lt[idx] = val[u];
        pos[u] = idx;
        idx++;

        if(hv[u]) {
            dfs2(hv[u], u, hd);
        }

        for(auto v : g[u]) {
            if((v ^ p) && (v ^ hv[u])) {
                dfs2(v, u, v);
            }
        }
    };

    dfs(1, 0);
    dfs2(1, 0, 1);

    for(int i = 0; i < 31; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    auto getAncestor = [&] (int u, int k) {
        for(int i = 30; i >= 0; i--) {
            if((k >> i) & 1) {
                u = dp[i][u];
            }
        }
        return u;
    };


    int base = 1;
    while(base <= 2 * n) base <<= 1;

    vector<int> Seg(2 * base);

    auto upd = [&] (int i, int v) {
        for(Seg[i += n] = v, i >>= 1; i; i >>= 1) Seg[i] = max(Seg[2 * i], Seg[2 * i + 1]);
    };

    auto qur = [&] (int l, int r) {
        int res = 0;
        for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) res = max(res, Seg[l++]);
            if(!(r & 1)) res = max(res, Seg[r--]);
        }
        return res;
    };

    for(int i = 1; i <= n; i++) upd(pos[i], lt[pos[i]]);


    auto update = [&] (int i, int v) {
        upd(i, v);
    };

    auto f = [&] (int u, int v) {
        int mx = 0;
        while(head[u] != head[v]) {
            if(dep[head[u]] < dep[head[v]]) swap(u, v);
            mx = max(mx, qur(pos[head[u]], pos[u]));
            u = par[head[u]];
        }
        if(dep[u] > dep[v]) swap(u, v);
        mx = max(mx, qur(pos[u], pos[v]));

        return (mx == 0);
    };

    auto query = [&] (int u) {
        if(lt[pos[u]]) return u;
        int l = 0, r = 1e6 + 10, best = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int v = getAncestor(u, mid);
            if(v && f(u, v)) {
                best = v;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if(best != -1) best = par[best];

        return (best ? best : -1);
    };

    while(q--) {
        int ty; cin>>ty;
        if(ty == 0) {
            int u; cin>>u;
            update(pos[u], 1 - lt[pos[u]]);
            lt[pos[u]] = 1 - lt[pos[u]];
        } else {
            int u; cin>>u;
            cout<<query(u)<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
