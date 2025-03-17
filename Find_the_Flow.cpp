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

void solve() {
    int m; cin>>m;
    vector<int> g[30];
    vector<vector<int>> cap(30, vector<int>(30));

    auto addEdge = [&] (int u, int v, int c) {
        g[u].push_back(v);
        g[v].push_back(u);
        cap[u][v] += c;
    };

    for(int i = 0; i < m; i++) {
        char u, v; int c; cin>>u>>v>>c;
        addEdge(u - 'A', v - 'A', c);
    }

    vector<int> par;

    auto bfs = [&] (int s, int t) {
        par = vector<int>(30, -1);
        queue<pii> q;
        q.push({s, INF});
        par[s] = 0;
        while(sz(q)) {
            auto [u, f] = q.front(); q.pop();
            for(int v : g[u]) {
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

    auto getFlow = [&] (int s, int t) {
        int flow = 0;
        while(int cur = bfs(s, t)) {
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

    cout<<getFlow('S' - 'A', 'T' - 'A')<<endl;
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