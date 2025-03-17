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
    int n, m; cin>>n>>m;
    vector<int> g[n + 1], gT[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        gT[v].push_back(u);
    }

    vector<int> vis(n + 1), ord;

    function<void(int)> dfs = [&] (int u) {
        vis[u] = 1;
        for(auto v : g[u]) {
            if(!vis[v]) dfs(v);
        }
        ord.push_back(u);
    };

    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);

    vector<int> comp(n + 1, -1);

    function<void(int, int)> dfs2 = [&] (int u, int ct) {
        comp[u] = ct;
        for(auto v : gT[u]) {
            if(comp[v] == -1) dfs2(v, ct);
        }
    };


    reverse(ord.begin(), ord.end());
    int ct = 0;
    for(int i : ord) {
        if(comp[i] == -1) dfs2(i, ct++);
    }

    // for(int i = 1; i <= n; i++) cerr<<comp[i]<<" \n"[i == n];

    vector<int> outDeg(n + 1);

    for(int u = 1; u <= n; u++) {
        for(int v : g[u]) {
            if(comp[u] ^ comp[v]) {
                outDeg[comp[u]]++;
            }
        }
    }

    int ctZero = 0, compNo = -1;
    for(int i = 0; i < ct; i++) {
        if(!outDeg[i]) ctZero++, compNo = i;
        if(ctZero > 1) {cout<<0<<endl; return; }
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(comp[i] == compNo) ans.push_back(i);
    }

    cout<<sz(ans)<<endl;
    for(int i = 0; i < sz(ans); i++) cout<<ans[i]<<" \n"[i == sz(ans)];
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