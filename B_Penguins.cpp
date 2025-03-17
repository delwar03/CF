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

struct Point {
    int x, y, p, q;
};

void solve() {
    int n; double d; cin>>n>>d;
    int sz = 2 * n + 10;
    vector<int> g[sz + 10];
    vector<vector<int>> cap(sz + 10, vector<int>(sz + 10));
    vector<Point> pts(n);
    int s = sz + 5, tot = 0;

    auto addEdge = [&] (int u, int v, int c) {
        g[u].push_back(v);
        g[v].push_back(u);
        cap[u][v] += c;
    };

    int id = 0;

    for(auto &[x, y, p, q] : pts) {
        cin>>x>>y>>p>>q;
        addEdge(s, id, p);
        addEdge(id, n + id, q);
        tot += p;
        id += 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i ^ j) {
            int dx = pts[i].x - pts[j].x, dy = pts[i].y - pts[j].y;
            if(1.0 * dx * dx + dy * dy <= d * d) {
                addEdge(n + i, j, pts[i].q);
            }
        }
    }

    vector<int> par;
    
    auto tmpCap = cap;

    auto bfs = [&] (int s, int t) {
        par = vector<int>(sz + 10, -1);
        par[s] = 0;
        queue<pair<int, int>> q;
        q.push({s, INF});
        while(!q.empty()) {
            auto [u, f] = q.front();
            q.pop();
            for(auto v : g[u]) {
                if(par[v] == -1 && tmpCap[u][v] > 0) {
                    par[v] = u;
                    int ff = min(f, tmpCap[u][v]);
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
            // for(auto it : par) cerr<<it<<" "; cerr<<endl;
            flow += cur;
            int tmp = t;
            while(tmp != s) {
                int prv = par[tmp];
                tmpCap[prv][tmp] -= cur;
                tmpCap[tmp][prv] += cur;
                tmp = prv;
            }
        }
        return flow;
    };

    vector<int> ans;

    for(int i = 0; i < n; i++) {
        tmpCap = cap;
        int fl = getFlow(s, i);
        // cerr<<"flow: "<<fl<<endl;
        if(fl == tot) {
            ans.push_back(i);
        }
    }

    if(ans.size()) {
        for(auto it : ans) cout<<it<<" "; cout<<endl;
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