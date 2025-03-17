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
    int n, m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    int sz = n + m + 10;
    vector<vector<int>> g(sz), cap(sz, vector<int>(sz));
    int s = n + m + 5, t = s + 1;

    auto addEdge = [&] (int u, int v, int c) {
        g[u].push_back(v);
        g[v].push_back(u);
        cap[u][v] += c;
    };

    for(int i = 0; i < n; i++) {
        addEdge(s, i, a[i]);
    }
    for(int j = 0; j < m; j++) {
        addEdge(n + j, t, b[j]);
    }

    for(int i = 0; i < n; i++) {
        int k; cin>>k;
        while(k--) {
            int x; cin>>x;
            --x;
            addEdge(i, n + x, a[i]);
        }
    }

    vector<int> par;

    auto bfs = [&] (int s, int t) {
        par = vector<int>(sz, -1);
        par[s] = 0;
        queue<pair<int, int>> q;
        q.push({s, INF});
        while(!q.empty()) {
            auto [u, f] = q.front();
            q.pop();
            for(int v : g[u]) if(par[v] == -1 && cap[u][v] > 0) {
                par[v] = u;
                int ff = min(f, cap[u][v]);
                if(v == t) return ff;
                q.push({v, ff});
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

    int tot = accumulate(a.begin(), a.end(), 0LL);

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