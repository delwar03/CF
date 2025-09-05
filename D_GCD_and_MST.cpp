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
    int n, p; cin >> n >> p;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    vector<pii> cur;
    for(int i = 0; i < n; i++) cur.push_back({v[i], i});
    sort(cur.begin(), cur.end());
    vector<int> vis(n);
    int ans = 0;
    for(auto [x, id] : cur) {
        if(x > p) break;
        int j = id;
        while(j - 1 >= 0 && !vis[j - 1] && v[j - 1] % x == 0) {
            ans += x;
            vis[j - 1] = 1;
            j--;
        }
        j = id;
        while(j + 1 < n && !vis[j] && v[j + 1] % x == 0) {
            ans += x;
            vis[j] = 1;
            j++;
        }
    }
    for(int i = 0; i < n - 1; i++) ans += p * !vis[i];
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}