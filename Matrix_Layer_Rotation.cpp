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
    int n, m, r; cin >> n >> m >> r;
    vector<vector<int>> v(n, vector<int>(m));
    for(auto &x : v) for(auto &y : x) cin >> y;

    for(int i = 0; i < min(n, m) / 2; i++) {
        vector<int> tmp;
        for(int j = i; j < m - i; j++) tmp.push_back(v[i][j]);
        for(int j = i + 1; j < n - i; j++) tmp.push_back(v[j][m - i - 1]);
        for(int j = m - i - 2; j >= i; j--) tmp.push_back(v[n - i - 1][j]);
        for(int j = n - i - 2; j > i; j--) tmp.push_back(v[j][i]);

        int sz = sz(tmp), id = r % sz;
        
        for(int j = i; j < m - i; j++) v[i][j] = tmp[(id++) % sz];
        for(int j = i + 1; j < n - i; j++) v[j][m - i - 1] = tmp[(id++) % sz];
        for(int j = m - i - 2; j >= i; j--) v[n - i - 1][j] = tmp[(id++) % sz];
        for(int j = n - i - 2; j > i; j--) v[j][i] = tmp[(id++) % sz];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << v[i][j] << " \n"[j == m - 1];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}