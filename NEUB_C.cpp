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

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n + 1) {
        bit = vector<int>(n + 1);
    }

    void add(int x, int val) {
        for(int i = x; i < n; i += i & -i) bit[i] += val;
    }

    int sum(int x) {
        int ret = 0;
        for(int i = x; i; i -= i & -i) ret += bit[i];
        return ret;
    }

    int qur(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int binPow(int a, int b) {
    int ret = 1;
    while(b > 0) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    BIT pf(n + 1), sf(n + 1);
    for(auto &x : v) cin >> x, sf.add(x, +1);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        sf.add(v[i], -1);
        int x = pf.sum(v[i] - 1), y = sf.sum(v[i] - 1);
        int cur = (binPow(2, x) - 1 + mod) * (binPow(2, y) - 1 + mod) % mod;
        ans = (ans + cur) % mod;
        pf.add(v[i], +1);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}