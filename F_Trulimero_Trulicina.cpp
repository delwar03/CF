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
    int n, m, k; cin>>n>>m>>k;
    vector grid(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        int f = 0;
        for(int j = 0; j < m; j++) {
            grid[i][j] = (i * m + j) % k + 1;
            if(i - 1 >= 0 && grid[i - 1][j] == grid[i][j]) f = 1;
        }
        if(f) {
            int x = grid[i][0];
            for(int j = 0; j < m - 1; j++) grid[i][j] = grid[i][j + 1];
            grid[i][m - 1] = x;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout<<grid[i][j]<<" \n"[j == m - 1];
    }
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