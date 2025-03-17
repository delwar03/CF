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

struct Point {
    int x, y, a, b;
};

void solve() {
    int n; double d; cin>>n>>d;
    vector<Point> pts;
    int sz = 2 * n + 5, s = sz - 1, t;
    vector<int> g[sz];
    vector<Node> edges;
    int tot = 0, id = 0;

    auto addEdge = [&] (int u, int v, int c) {
        edges.push_back({u, v, c});
        edges.push_back({v, u, 0});
        g[u].push_back(id);
        g[v].push_back(id + 1);
        id += 2;
    };

    for(int i = 0; i < n; i++) {
        int x, y, a, b; cin>>x>>y>>a>>b;
        pts.push_back({x, y, a, b});
        addEdge(s, i, a);
        addEdge(i, n + i, b);
        tot += a;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i ^ j) {
            int dx = pts[i].x - pts[j].x, dy = pts[i].y - pts[j].y;
            if(dx * dx + dy * dy <= d * d) {
                addEdge(n + i, j, pts[i].b);
            }
        }
    }

    auto tmp = edges;
    vector<int> dep, ptr;

    function<int(int, int)> dfs = [&] (int u, int f) {
        if(f == 0 || u == t) return f;
        for(int &i = ptr[u]; i < sz(g[u]); i++) {
            int id = g[u][i], v = edges[id].v;
            if(dep[v] != dep[u] + 1) continue;
            int cur = dfs(v, min(f, edges[id].cap - edges[id].flow));
            if(cur) {
                edges[id].flow += cur;
                edges[id ^ 1].flow -= cur;
                return cur;
            }
        }
        return 0LL;
    };

    auto bfs = [&] (int s, int t) {
        dep = vector<int>(sz + 1, -1);
        queue<int> q;
        q.push(s);
        dep[s] = 0;
        while(sz(q)) {
            auto u = q.front(); q.pop();
            for(auto id : g[u]) {
                int v = edges[id].v;
                if(edges[id].cap == edges[id].flow || dep[v] != -1) continue;
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
        return dep[t] != -1;
    };

    auto getFlow = [&] (int s, int t) {
        int flow = 0;
        while(bfs(s, t)) {
            ptr = vector<int>(sz + 1, 0);
            while(int f = dfs(s, INF)) flow += f;
        }
        return flow;
    };

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        t = i;
        edges = tmp;
        if(getFlow(s, t) == tot) ans.push_back(i);
    }
    if(sz(ans)) {
        for(int i = 0; i < sz(ans); i++) cout<<ans[i]<<" \n"[i == sz(ans) - 1];
    } else {
        cout<<-1<<endl;
    }
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