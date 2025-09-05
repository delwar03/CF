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
const int N = 1e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    array<int, 2> cnt[32]{}, sm[32]{};
    int ans = 0, pf = 0;
    for(int i = 0; i <= n; i++) {
        pf ^= v[i];
        for(int j = 0; j < 32; j++) {
            int f = pf >> j & 1;
            (cnt[j][f] += 1) %= mod;
            (sm[j][f] += i) %= mod;
            (ans += (1LL << j) * (cnt[j][!f] * i % mod - sm[j][!f] + mod) % mod) %= mod;
        }
    }
    cout << ans << endl;
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