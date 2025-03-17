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
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt[2];
    cnt[0] = 2;
    cnt[1] = 2 * n;
    vector<int> dep(n + 1), ans(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dep[v] = 1 + dep[u];
                dfs(v, u);
            }
        }
    };

    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        int f = dep[i] & 1;
        ans[i] = cnt[f];
        cnt[f] += (f ? -2 : +2);
    }

    int f = 0;

    for(int u = 1; u <= n; u++) {
        for(auto v : g[u]) {
            if(dep[v] < dep[u]) continue;
            if(abs(ans[u] - ans[v]) == 2) {
                ans[v] = ans[u] - 1;
                f = 1;
                break;
            }
        }
        if(f) break;
    }

    for(int i = 1; i <= n; i++) cout<<ans[i]<<" "; cout<<endl;
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