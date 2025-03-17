#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    int n, d; cin>>n>>d;
    vector<pii> dir;
    for(int i = -d; i <= d; i++) {
        for(int j = -d; j <= d; j++) {
            if(i * i + j * j == d * d) {
                dir.push_back({i, j});
            }
        }
    }
    int s = n + 5, t = s + 1;
    vector<int> g[n + 10];
    map<pii, int> mp;
    for(int i = 1; i <= n; i++) {
        int x, y; cin>>x>>y;
        for(auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if(mp.count({nx, ny})) {
                int id = mp[{nx, ny}];
                g[i].push_back(id);
                g[id].push_back(i);
            }
        }
        mp[{x, y}] = i;
    }

    vector<int> col(n + 10, -1);

    function<void(int)> dfs = [&] (int u) {
        for(auto v : g[u]) {
            if(col[v] == -1) {
                col[v] = 1 - col[u];
                dfs(v);
            }
        }
    };

    for(int i = 1; i <= n; i++) {
        if(col[i] == -1) {
            col[i] = 0;
            dfs(i);
        }
    }

    vector<vector<int>> cap(n + 10, vector<int>(n + 10));

    for(int i = 1; i <= n; i++) {
        if(col[i] == 0) {
            g[s].push_back(i);
            g[i].push_back(s);
            cap[s][i] += 1;
            for(auto v : g[i]) {
                cap[i][v] += 1;
            }
        } else {
            g[i].push_back(t);
            g[t].push_back(i);
            cap[i][t] += 1;
        }
    }


    vector<int> par;

    auto bfs = [&] (int s, int t) {
        par = vector<int>(n + 10, -1);
        par[s] = 0;
        queue<pair<int, int>> q;
        q.push({s, INF});
        while(!q.empty()) {
            auto [u, f] = q.front();
            q.pop();
            for(auto v : g[u]) {
                if(par[v] == -1 && cap[u][v] > 0) {
                    par[v] = u;
                    int ff = min(f, cap[u][v]);
                    if(v == t) return ff;
                    q.push({v, ff});
                }
            }
        }
        return 0LL;
    };

    int flow = 0, cur = 0;

    auto getFlow = [&] (int s, int t) {
        while(cur = bfs(s, t)) {
            flow += cur;
            int tmp = t;
            while(tmp != s) {
                int prv = par[tmp];
                cap[prv][tmp] -= cur;
                cap[tmp][prv] += cur;
                tmp = prv;
            }
        }
        return flow;
    };

    cout<<getFlow(s, t)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}