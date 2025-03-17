#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<vector<int>> g[n + 1];
    vector<int> mpp(n + 1, 0), val(n + 1, 0);
    for(int i = 1; i <= n - 1; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt, i});
        g[v].push_back({u, wt, i});
    }

    vector<int> sz(n + 1, 0), par(n + 1, 0), dep(n + 1, 0), hv(n + 1, 0), head(n + 1, 0), pos(n + 1, 0), lt(n + 1, 0);
    int idx = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto it : g[u]) {
            int v = it[0], wt = it[1], i = it[2];
            if(v ^ p) {
                dep[v] = 1 + dep[u];
                par[v] = u;
                mpp[i] = v;
                val[v] = wt;
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

        for(auto it : g[u]) {
            int v = it[0], wt = it[1], i = it[2];
            if((v ^ p) && (v ^ hv[u])) {
                dfs2(v, u, v);
            }
        }
    };

    dfs(1, 0);
    dfs2(1, 0, 1);

    int base = 1;
    while(base <= 2 * n) base <<= 1;

    vector<int> Seg(2 * base);

    auto update = [&] (int i, int v) {
        for(Seg[i += n] = v, i >>= 1; i; i >>= 1) Seg[i] = max(Seg[2 * i], Seg[2 * i + 1]);
    };

    auto que = [&] (int l, int r) {
        int res = 0;
        for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) res = max(res, Seg[l++]);
            if(!(r & 1)) res = max(res, Seg[r--]);
        }
        return res;
    };

    for(int i = 1; i <= n; i++) update(pos[mpp[i]], lt[pos[mpp[i]]]);

    auto query = [&] (int u, int v) {
        int res = 0;
        while(head[u] != head[v]) {
            if(dep[head[u]] < dep[head[v]]) swap(u, v);
            res = max(res, que(pos[head[u]], pos[u]));
            u = par[head[u]];
        }
        if(dep[u] > dep[v]) swap(u, v);
        if(u != v)
            res = max(res, que(pos[u] + 1, pos[v]));

        return res;
    };

    while(1) {
        string ty; cin>>ty;
        if(ty == "QUERY") {
            int u, v; cin>>u>>v;
            cout<<query(u, v)<<endl;
        } else if(ty == "CHANGE") {
            int i, v; cin>>i>>v;
            update(pos[mpp[i]], v);
            lt[pos[mpp[i]]] = v;
        } else {
            break;
        }
    }
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