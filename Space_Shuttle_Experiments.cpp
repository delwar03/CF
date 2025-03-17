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

struct Node {
    int u, v, cap, flow = 0;
};

void solve() {
    int n, m; cin>>n>>m;
    vector<int> P(n + 1), C(m + 1);
    int tot = 0;
    for(int i = 1; i <= n; i++) cin>>P[i], tot += P[i];
    for(int i = 1; i <= m; i++) cin>>C[i];

    int sz = n + m + 10, s = sz - 1, t = sz - 2;
    vector<int> g[sz];
    vector<Node> edges;
    int id = 0;

    auto addEdge = [&] (int u, int v, int c) {
        edges.push_back({u, v, c});
        edges.push_back({v, u, 0});
        g[u].push_back(id);
        g[v].push_back(id + 1);
        id += 2;
    };

    for(int i = 1; i <= n; i++) {
        int k; cin>>k;
        while(k--) {
            int x; cin>>x;
            addEdge(i, n + x, INF);
        }
    }
    for(int i = 1; i <= n; i++) addEdge(s, i, P[i]);
    for(int i = 1; i <= m; i++) addEdge(i + n, t, C[i]);

    auto getFlow = [&] (int s, int t) {

        vector<int> ptr, dep;

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

        auto bfs = [&] {
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
        while(bfs()) {
            ptr = vector<int>(sz, 0);
            while(int f = dfs(s, INF)) flow += f;
        }
        return flow;
    };

    cout<<tot - getFlow(s, t)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}