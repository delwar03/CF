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
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(auto &x : v) cin >> x;

    vector<int> mx(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mx[j] = max(mx[j], int(v[i][j] - '0'));
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int f = 0;
        for(int j = 0; j < m; j++) {
            if(v[i][j] - '0' == mx[j]) f = 1;
        }
        cnt += f;
    }

    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}