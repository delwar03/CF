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
    string s; cin>>s;
    vector<array<int, 8>> v(n);
    for(auto &x : v) for(auto &y : x) cin>>y;
    string ans(n, '?');

    auto get = [&] (int d, int i, int j) {
        return (d + d * v[i][j] + v[i][j + 1]) % m;
    };

    function<bool(int, int)> dfs = [&] (int i, int d) {
        if(i == n) return min(d, m - d) <= k;

        if(s[i] == 'T') {
            // try bottom
            int d1 = get(d, i, 6), d2 = get(d, i, 4);
            if(dfs(i + 1, d1) && dfs(i + 1, d2)) {
                ans[i] = 'B';
                return true;
            }
            // top
            d1 = get(d, i, 2), d2 = get(d, i, 0);
            ans[i] = 'T';
            return dfs(i + 1, d1) && dfs(i + 1, d2);
        } else {
            // try bottom
            int d1 = get(d, i, 4), d2 = get(d, i, 6);
            if(dfs(i + 1, d1) && dfs(i + 1, d2)) {
                ans[i] = 'B';
                return true;
            }
            // top
            d1 = get(d, i, 0), d2 = get(d, i, 2);
            ans[i] = 'T';
            return dfs(i + 1, d1) && dfs(i + 1, d2);
        }
    };

    dfs(0, 0);
    cout<<ans<<endl;
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