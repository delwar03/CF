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
    int n; cin>>n;
    vector<int> r(n + 1), g[n + 1], rg[n + 1];
    for(int i = 1; i <= n; i++) {
        cin>>r[i];
        g[i].push_back(r[i]);
        rg[r[i]].push_back(i);
    }

    vector<int> cyc(n + 1), vis(n + 1), dep(n + 1), tmp;
    int ans = 0;

    queue<pii> q;

    function<bool(int)> dfs1 = [&] (int u) {
        vis[u] = 2;
        tmp.push_back(u);
        for(auto v : g[u]) {
            if(!vis[v]) {
                if(dfs1(v)) return true;
            } else if(vis[v] == 2) {
                for(auto it = find(tmp.begin(), tmp.end(), v); it != tmp.end(); it++) {
                    // cerr<<"v: "<<*it<<endl;
                    cyc[*it] = 1;
                    // pii p = {*it, 0};
                    // q.push(p);
                }
                return true;
            }
        }
        vis[u] = 1;
        tmp.pop_back();
        return false;
    };

    function<void(int, int)> dfs2 = [&] (int u, int d) {
        for(auto v : rg[u]) {
            if(cyc[v]) continue;
            dfs2(v, 1 + d);
        }
        ans = max(ans, d);
    };


    for(int i = 1; i <= n; i++) if(!vis[i]) {
        tmp.clear();
        dfs1(i);
    }

    for(int i = 1; i <= n; i++) cerr<<cyc[i]<<" "; cerr<<endl;

    // for(int i = 1; i <= n; i++) if(cyc[i]) {
    //     q.push({i, 0});
    // }

    // for(int i = 1; i <= n; i++) if(!cyc[i] && cyc[r[i]]) {
    //     dfs2(i, 0);
    // }

    ans = 0;

    while(sz(q)) {
        auto [u, d] = q.front(); q.pop();
        ans = max(ans, d);
        for(auto v : rg[u]) {
            q.push({v, 1 + d});
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}