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

int F[N], I[N], IF[N];

int nCr(int n, int r) {
    if(n < r) return 0;
    return F[n] * IF[r] % mod * IF[n - r] % mod;
}

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<int> pf(n);
    for(int i = 0; i <= n; i++) (pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0LL) + nCr(i, k)) %= mod;

    map<int, pii> mp;
    mp[0] = {0, 0};
    int sm = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        char ch = s[i];
        sm += (ch == '1');
        if(mp.count(sm - k)) {
            auto [a, b] = mp[sm - k];
            int l = (i - b + 1), r = (i - a + 1);
            (ans += (pf[r] - (l - 1 >= 0 ? pf[l - 1] : 0LL) + mod)) %= mod;
        }

        cerr<<ans<<" "<<sm<<endl;

        if(mp.count(sm)) {
            mp[sm].S = i;
        } else {
            mp[sm] = {i, i};
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    F[0] = IF[0] = I[1] = 1;
    for(int i = 2; i < N; i++) I[i] = mod - (mod / i) * I[mod % i] % mod;
    for(int i = 1; i < N; i++) F[i] = F[i - 1] * i % mod, IF[i] = IF[i - 1] * I[i] % mod;

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}