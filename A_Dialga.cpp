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
const int mod = 1e9 + 33;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector<string> v(n);
    for(auto &x : v) cin >> x;

    int prod = 1;
    for(auto x : v) {
        int cur = 0;
        for(int i = 0; i < sz(x); i++) {
            cur = (cur * 10 + (x[i] - '0')) % mod;
        }
        prod = prod * cur % mod;
    }

    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) ret = ret * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ret;
    };

    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = 0; j < sz(v[i]); j++) {
            cur = (cur * 10 + (v[i][j] - '0')) % mod;
        }
        if(binPow(cur, n) == prod) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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