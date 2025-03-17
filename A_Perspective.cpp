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
    int n; cin>>n;
    vector<int> w(n + 1), r(n + 1);
    vector<vector<int>> p(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) cin>>w[i];
    for(int i = 1; i <= n; i++) cin>>r[i];
    int sm = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin>>p[i][j];
            if(i != 1 && j != 1) sm += p[i][j];
        }
    }

    sm /= 2;
    int sz = n * n + n + 10, s = sz - 1, t = sz - 2;
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

    int mxW = w[1] + r[1];

    for(int i = 2; i <= n; i++) {
        if(mxW < w[i]) {cout<<"NO"<<endl; return; }
        addEdge(n * n + i, t, min(r[i], mxW - w[i]));
    }

    for(int i = 2; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(!p[i][j]) continue;
            addEdge(s, n * (i - 1) + j, p[i][j]);
            addEdge(n * (i - 1) + j, n * n + i, p[i][j]);
            addEdge(n * (i - 1) + j, n * n + j, p[i][j]);
        }
    }

    vector<int> ptr(sz + 1, 0), dep(sz + 1, -1);

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

    auto bfs = [&] {
        dep = vector<int>(sz + 1, -1);
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

    auto getFlow = [&] {
        int flow = 0;
        while(bfs()) {
            ptr = vector<int>(sz + 1, 0);
            while(int f = dfs(s, INF)) flow += f;
        }
        return flow;
    };

    int f = getFlow();
    // cerr<<f<<" "<<sm<<endl;
    cout<<(f == sm ? "YES" : "NO")<<endl;
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