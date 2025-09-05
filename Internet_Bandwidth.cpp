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
    int u, v, cap, flow;
};

void solve() {
    int n; cin>>n;
    int s, t, m; cin>>s>>t>>m;
    vector<int> g[n + 1];
    vector<Node> edges;
    int id = 0;

    auto addEdge = [&] (int u, int v, int c) {
        edges.push_back({u, v, c});
        edges.push_back({v, u, c});
        g[u].push_back(id);
        g[v].push_back(id + 1);
        id += 2;
        return id - 2;
    };

    while(m--) {
        int u, v, c; cin>>u>>v>>c;
        addEdge(u, v, c);
    }

    auto getFlow = [&] (int s, int t) {

        vector<int> dep, ptr;

        function<int(int, int)> dfs = [&] (int u, int f) {
            if(f == 0 || u == t) return f;
            for(int &i = ptr[u]; i < sz(g[u]); i++) {
                int id = g[u][i], v = edges[id].v;
                if(dep[v] != dep[u] + 1) continue;
                int ff = dfs(v, min(f, edges[id].cap - edges[id].flow));
                if(ff > 0) {    
                    edges[id].flow += ff;
                    edges[id ^ 1].flow -= ff;
                    return ff;
                }
            }
            return 0LL;
        };

        auto bfs = [&] () {
            dep = vector<int>(n + 1, -1);
            queue<int> q;
            q.push(s);
            dep[s] = 0;
            while(sz(q)) {
                int u = q.front(); q.pop();
                for(auto id : g[u]) {
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
            ptr = vector<int>(n + 1, 0);
            while(int f = dfs(s, INF)) flow += f;
        }
        return flow;
    };

    cout<<getFlow(s, t)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        cout<<"Case "<<tc<<": ";
        solve();
    }
}