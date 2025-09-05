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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int binPow(int a, int b) {
    int ret = 1;
    while(b > 0) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int inv(int n) {
    return binPow(n, mod - 2);
}

int n, m; 
int dp[N];
vector<pii> g[N];

int magic(int i) {
    if(i > m) return 1;
    int &ans = dp[i];
    if(~ans) return ans;
    ans = 0;
    for(auto [j, p] : g[i]) {
        ans = (ans + p * magic(j + 1)) % mod;
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    int tot = 1;
    for(int i = 0; i < n; i++) {
        int l, r, p, q; cin >> l >> r >> p >> q;
        int pb = p * inv(q) % mod;
        tot = tot * (1 - pb + mod) % mod;
        g[l].push_back({r, pb * inv(1 - pb + mod) % mod});
    }
    memset(dp, -1, sizeof dp);
    cout << tot * magic(1) % mod << endl;
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