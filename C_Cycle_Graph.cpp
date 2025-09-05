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
    vector<int> deg(n + 1), par(n + 1), siz(n + 1, 1);
    iota(par.begin(), par.end(), 0LL);

    function<int(int)> find = [&] (int u) {
        return (par[u] == u ? u : par[u] = find(par[u]));
    };

    auto join = [&] (int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return false;
        if(siz[u] < siz[v]) u ^= v ^= u ^= v;
        par[v] = u;
        siz[u] += siz[v];
        return true;
    };

    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        deg[u]++; deg[v]++;
        join(u, v);
    }
    for(int i = 1; i <= n; i++) if(deg[i] != 2) {
        cout<<"No"<<endl; return;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += (find(i) == i);
    cout<<(cnt == 1 ? "Yes" : "No")<<endl;
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