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
    int n; cin >> n;
    vector<int> vis(n + 1), ev, th;
    for(int i = 2; i <= n; i += 2) ev.push_back(i), vis[i] = 1;
    for(int i = 3; i <= n; i += 6) th.push_back(i), vis[i] = 1;

    int j = 1;
    vector<int> ans;
    while(sz(ev) > 1) {
        int x = ev.back(); ev.pop_back();
        int y = ev.back(); ev.pop_back();
        while(vis[j]) j++;
        ans.push_back(x), ans.push_back(j), ans.push_back(y);
        vis[j] = 1;
    }
    while(sz(th) > 1) {
        int x = th.back(); th.pop_back();
        int y = th.back(); th.pop_back();
        while(vis[j]) j++;
        ans.push_back(x), ans.push_back(j), ans.push_back(y);
        vis[j] = 1;
    }
    while(sz(ev)) ans.push_back(ev.back()), ev.pop_back();
    while(sz(th)) ans.push_back(th.back()), th.pop_back();
    while(sz(ans) < n) {
        while(vis[j]) j++;
        ans.push_back(j);
        vis[j] = 1;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}