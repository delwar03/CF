#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dp[12][12][12];

void solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    int ans = 0;

    auto valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && v[i][j] == '.';
    };

    function<void(int, int, int)> dfs = [&] (int i, int j, int f) {
        if(f == 0) {
            ans += 1;
            return;
        }
        v[i][j] = '#';
        for(int d = 0; d < 4; d++) {
            int ni = i + dir[d][0], nj = j + dir[d][1];
            if(valid(ni, nj)) {
                dfs(ni, nj, f - 1);
            }
        }
        v[i][j] = '.';
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '#') continue;
            dfs(i, j, k);
            // cerr<<"i: "<<i<<", j: "<<j<<", ans: "<<ans<<endl;
        }
    }
    cout<<ans<<endl;
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

/*
i/p: 
o/p: 
*/