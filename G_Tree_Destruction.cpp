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

    int ans = 1;

    function<int(int, int)> dfs = [&] (int u, int p) {
        int cur = sz(g[u]) - 2, mx1 = 1, mx2 = 1;
        for(auto v : g[u]) {
            if(v ^ p) {
                int x = dfs(v, u);
                if(x > mx1) {
                    mx2 = mx1;
                    mx1 = x;
                } else if(x > mx2) {
                    mx2 = x;
                }
            }
        }
        ans = max(ans, mx1 + mx2 + cur);
        return mx1 + cur;
    };

    dfs(1, 0);
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