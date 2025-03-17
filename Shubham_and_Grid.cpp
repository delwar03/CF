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

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve() {
    int n, m; cin>>n>>m;
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string tmp;
        for(int j = 0; j < m; j++) {
            char ch; cin>>ch;
            tmp += ch;
        }
        v.push_back(tmp);
    }
    
    int sz = 2 * n * m + 10;
    int s = 2 * n * m + 5, t = s + 1;
    vector<int> g[sz + 10];
    vector<vector<int>> cap(sz + 10, vector<int>(sz + 10));

    auto valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    auto getId = [&] (int i, int j) {
        return m * i + j + 1;
    };

    auto addEdge = [&] (int u, int v, int c) {
        g[u].push_back(v);
        g[v].push_back(u);
        cap[u][v] += c;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'a') {
                addEdge(s, getId(i, j), +1);
                for(int d = 0; d < 4; d++) {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if(valid(ni, nj) && v[ni][nj] == 'b') {
                        addEdge(getId(i, j), getId(ni, nj), +1);
                    }
                }
            } else if(v[i][j] == 'b') {
                addEdge(getId(i, j), n * m + getId(i, j), +1);
                for(int d = 0; d < 4; d++) {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if(valid(ni, nj) && v[ni][nj] == 'c') {
                        addEdge(n * m + getId(i, j), getId(ni, nj), +1);
                    }
                }
            } else if(v[i][j] == 'c') {
                addEdge(getId(i, j), n * m + getId(i, j), +1);
                for(int d = 0; d < 4; d++) {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if(valid(ni, nj) && v[ni][nj] == 'd') {
                        addEdge(n * m + getId(i, j), getId(ni, nj), +1);
                    }
                }
            } else {
                addEdge(getId(i, j), t, +1);
            }
        }
    }

    vector<int> par;

    auto bfs = [&] (int s, int t) {
        par = vector<int>(sz + 10, -1);
        par[s] = 0;
        queue<pii> q;
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

/*
i/p: 
o/p: 
*/