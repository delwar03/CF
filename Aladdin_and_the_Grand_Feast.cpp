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
    int n, t, c, e; cin>>n>>t>>c>>e;
    vector<int> st(n), en(n), fd(n), vals;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        cin>>st[i]>>en[i]>>fd[i];
        tot += fd[i];
        vals.push_back(st[i]);
        vals.push_back(en[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<pii> seg;
    for(int i = 1; i < sz(vals); i++) {
        seg.push_back({vals[i - 1], vals[i]});
    }

    int m = sz(seg);
    int sz = n + m + 10, ss = sz - 1, tt = sz - 2;
    vector<int> g[sz];
    vector<Node> edges;
    int id = 0;

    auto addEdge = [&] (int u, int v, int c) {
        edges.push_back({u, v, c});
        edges.push_back({v, u, 0});
        g[u].push_back(id);
        g[v].push_back(id + 1);
        id += 2;
        return id - 2;
    };

    vector<vector<int>> idx(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(st[i] <= seg[j].F && seg[j].S <= en[i]) {
                idx[i][j] = addEdge(i, j + n, seg[j].S - seg[j].F);
            }
        }
    }
    for(int i = 0; i < n; i++) addEdge(ss, i, fd[i]);
    for(int i = 0; i < m; i++) addEdge(i + n, tt, (seg[i].S - seg[i].F) * t * c);

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

        auto bfs = [&] {
            dep = vector<int>(sz, -1);
            queue<int> q;
            q.push(s);
            dep[s] = 0;
            while(sz(q)) {
                auto u = q.front(); q.pop();
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

    if(getFlow(ss, tt) != tot) {cout<<"No"<<endl; return; }

    cout<<"Yes"<<endl;

    vector<pii> ct[m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(st[i] <= seg[j].F && seg[j].S <= en[i]) {
                ct[j].push_back({i, edges[idx[i][j]].flow});
            }
        }
    }

    vector<string> ans(e - 1, string(t * c + t - 1, '.'));
    for(auto &v : ans) {
        for(int i = c; i < sz(v); i += c + 1) v[i] = '|';
    }

    auto get = [&] (int i) {
        if(i < 26) return char(i + 'a');
        return char(i - 26 + 'A');
    };

    for(int i = 0; i < m; i++) {
        int x = seg[i].F, y = 0;
        for(auto [a, b] : ct[i]) {
            for(int j = 0; j < b; j++, x++) {
                if(x == seg[i].S) x = seg[i].F, y++;
                if(ans[x - 1][y] == '|') y++;
                ans[x - 1][y] = get(a);
            }
        }
    }

    for(auto it : ans) cout<<it<<endl;
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