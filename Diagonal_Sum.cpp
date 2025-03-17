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
const int INF = 1e12 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int u, v, cap, flow = 0;
};

void solve() {
    int n, m; cin>>n>>m;
    int e = n + m, sm1 = 0, sm2 = 0;
    vector<int> a(e), b(e);
    for(int i = 1; i < e; i++) cin>>a[i], sm1 += a[i];
    for(int i = 1; i < e; i++) cin>>b[i], sm2 += b[i];

    if(sm1 != sm2) {cout<<"-1"<<endl; return; }

    int sz = 2 * e + 10, s = sz - 1, t = sz - 2;
    vector<int> g[sz];
    vector<Node> edges;
    int id = 0;

    vector<vector<int>> idx(n + 1, vector<int>(m + 1));

    auto addEdge = [&] (int u, int v, int c) {
        edges.push_back({u, v, c});
        edges.push_back({v, u, 0});
        g[u].push_back(id);
        g[v].push_back(id + 1);
        id += 2;
        return id - 2;
    };

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int u = i + j - 1, v = i - j + m;
            --a[u]; --b[v];
            idx[i][j] = addEdge(u, v + e, 99);
        }
    }
    for(int i = 1; i < e; i++) addEdge(s, i, a[i]);
    for(int i = 1; i < e; i++) addEdge(i + e, t, b[i]);

    auto getFlow = [&] (int s, int t) {

        vector<int> dep, ptr;

        function<int(int, int)> dfs = [&] (int u, int f) {
            if(f == 0 || u == t) return f;
            for(int &i = ptr[u]; i < sz(g[u]); i++) {
                int id = g[u][i], v = edges[id].v;
                if(dep[v] != dep[u] + 1) continue;
                int cur = dfs(v, min(f, edges[id].cap - edges[id].flow));
                if(cur > 0) {
                    edges[id].flow += cur;
                    edges[id ^ 1].flow -= cur;
                    return cur;
                }
            }
            return 0LL;
        };

        auto bfs = [&] (int s, int t) {
            dep = vector<int>(sz, -1);
            queue<int> q;
            q.push(s);
            dep[s] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int id : g[u]) {
                    int v = edges[id].v;
                    if(edges[id].cap == edges[id].flow || dep[v] != -1) continue;
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
            return dep[t] != -1;
        };

        int flow = 0;
        while(bfs(s, t)) {
            ptr = vector<int>(sz, 0);
            while(int f = dfs(s, INF)) flow += f;
        }
        return flow;
    };

    int f = getFlow(s, t);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout<<edges[idx[i][j]].flow + 1<<" \n"[j == m];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": \n";
        solve();
    }
}