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
const int N = 1e2 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int F[N], spf[N];

int get(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    function<int(int, int)> magic = [&] (int i, int j) {
        if(i == n && j == n) return n;
        int &ans = dp[i][j];
        if(~ans) return ans;
        ans = INF;
        if(i + 1 <= n)
            ans = min(ans, gcd(i, j) + magic(i + 1, j));
        if(j + 1 <= n)
            ans = min(ans, gcd(i, j) + magic(i, j + 1));
        return ans;
    };

    return magic(1, 1);
}

void solve(int n) {
    // int n; cin >> n;
    int ans = 3 * n - 2;
    if(spf[n] ^ n) ans += spf[n] - 1;
    cerr << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(spf, spf + N, 0LL);
    for(int i = 2; i < N; i++) {
        if(spf[i] ^ i) continue;
        for(int j = i + i; j < N; j += i) {
            if(spf[j] == j) spf[j] = i;
        }
    }

    for(int i = 1; i < N; i++) F[i] = get(i);

    for(int i = 1; i <= 100; i++) {cerr << i << " -> " << F[i] << " "; solve(i);}

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        // solve();
    }
}