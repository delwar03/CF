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
    vector<int> g[n + 1], indeg(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        indeg[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) q.push(i);
    }

    vector<int> ord;

    while(q.size()) {
        if(sz(q) > 1) {cout<<"No"<<endl; return; }
        int u = q.front(); q.pop();
        ord.push_back(u);
        int cnt = 0;
        for(auto v : g[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v), cnt++;
        }
    }

    cout<<"Yes"<<endl;
    vector<int> ans(n + 1);
    int x = 1;
    for(auto i : ord) ans[i] = x++;
    for(int i = 1; i <= n; i++) {
        if(ans[i] == 0) ans[i] = x++;
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<" "; cout<<endl;
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