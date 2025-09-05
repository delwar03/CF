#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    int n, m, k; cin>>n>>m>>k;
    vector<int> g[n];
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<bool> vis(n);
    int cnt = 0;
    queue<pii> q;

    auto push = [&] (int t) {
        if(cnt == n) return;
        queue<pii> tmp;
        while(sz(q)) {
            auto [u, d] = q.front(); q.pop();
            if(d == t) tmp.push({u, 0});
            if(vis[u] && d > 0) continue;
            vis[u] = 1;
            cnt++;
            for(auto v : g[u]) {
                if(!vis[v] && d + 1 <= t) {
                    q.push({v, d + 1});
                }
            }
        }
        q = tmp;
    };

    while(k--) {
        int t, u; cin>>t>>u; --u;
        if(t == 1) {
            if(vis[u]) continue;
            vis[u] = 1;
            q.push({u, 0});
        } else if(t == 2) {
            push(u + 1);
        } else {
            cout<<(vis[u] ? "YES" : "NO")<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}