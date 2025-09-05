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
const int N = 5e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int best[N], dp[25][N];
vector<int> g[N];

void solve() {
    int n, m; cin>>n>>m;
    vector<pii> v(n);
    for(auto &[a, b] : v) cin>>a>>b, g[a].push_back(b);

    for(int i = 0; i < N; i++) {
        if(i) best[i] = best[i - 1];
        for(int j : g[i]) {
            best[i] = max(best[i], j);
        }
        dp[0][i] = max(best[i], i);
    }

    for(int i = 1; i < 25; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    while(m--) {
        int l, r; cin>>l>>r;
        int cnt = 0, tmp = l;
        for(int i = 24; i >= 0; i--) if(dp[i][tmp] < r) {
            tmp = dp[i][tmp];
            cnt += (1LL << i);
        }
        cout<<(dp[0][tmp] >= r ? cnt + 1 : -1)<<endl;
    }
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