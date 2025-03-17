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
    
    vector<int> down(n + 1), up(n + 1);

    function<void(int, int)> dfs_down = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs_down(v, u);
                down[u] = max(down[u], 1 + down[v]);
            }
        }
    };


    function<void(int, int)> dfs_up = [&] (int u, int p) {
        vector<int> pref, suff;
        for(auto v : g[u]) {
            if(v ^ p) {
                pref.push_back(down[v]);
                suff.push_back(down[v]);
            }
        }

        int k = sz(pref);

        for(int i = 1; i < k; i++) pref[i] = max(pref[i], pref[i - 1]);
        for(int i = k - 2; i >= 0; i--) suff[i] = max(suff[i], suff[i + 1]);

        int i = 0;

        for(auto v : g[u]) {
            if(v ^ p) {
                int left = (i - 1 >= 0 ? pref[i - 1] : -1);
                int right = (i + 1 < k ? suff[i + 1] : -1);

                up[v] = max(up[v], 2 + max(left, right));
                up[v] = max(up[v], 1 + up[u]);
                i += 1;
                dfs_up(v, u);
            }
        }
    };

    dfs_down(1, 0);
    dfs_up(1, 0);

    int mx = 0;

    for(int i = 1; i <= n; i++) {
        mx = max(mx, up[i] + down[i]);
    }

    for(int i = 1; i <= n; i++) {
        int ans = mx;
        ans = max(ans, up[i] + 1);
        ans = max(ans, down[i] + 1);
        cout<<ans<<endl;
    }
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