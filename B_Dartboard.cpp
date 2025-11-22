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
    int n, m, k; cin >> n >> m >> k;
    vector<int> val(n), area(n);
    for(auto &x : val) cin >> x;

    auto getArea = [&] (vector<pii>& poly) {
        int ret = 0, n = sz(poly);
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            ret += poly[i].F * poly[j].S - poly[j].F * poly[i].S;
        }
        return ret;
    };

    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) ret = ret * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ret;
    };

    auto inv = [&] (int a) {
        return binPow(a, mod - 2);
    };

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        vector<pii> poly(k);
        for(auto &[x, y] : poly) cin >> x >> y;
        area[i] = getArea(poly);
    }

    vector<int> dif(n), pf(n);
    for(int i = 0; i < n; i++) dif[i] = area[i] - (i - 1 >= 0 ? area[i - 1] : 0);
    for(int i = 0; i < n; i++) pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0) + dif[i] * val[i];

    int mxId = 0;
    for(int i = 0; i < n; i++) {
        if(pf[i] * area[mxId] > pf[mxId] * area[i]) mxId = i;
    }

    int ans = (pf[mxId] * inv(area[mxId]) % mod) * k % mod;
    int sm = 0;
    for(int i = 0; i < n; i++) {
        int cur = area[i] - (i - 1 >= 0 ? area[i - 1] : 0);
        (sm += (cur * inv(area.back()) % mod) * val[i]) %= mod;
    }
    (ans += (m - k) * sm % mod) %= mod;

    cout << ans << endl;
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