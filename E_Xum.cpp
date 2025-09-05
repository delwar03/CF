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
    int x; cin >> x;

    vector<array<int, 3>> ans;
    ans.push_back({x, x, 1});

    auto mul = [&] (int x, int k) {
        int a = x, b = k, ret = 0;
        while(b > 0) {
            if(b & 1) ans.push_back({ret, a, 0}), ret += a;
            ans.push_back({a, a, 0}), a += a;
            b >>= 1;
        }
        assert(ret == x * k);
    };

    auto make = [&] (int x, int y, int m) {
        for(int i = 0; i * y <= m; i++) {
            int rem = m - i * y;
            if(rem % x == 0) {
                int j = rem / x;
                mul(y, i);
                mul(x, j);
                ans.push_back({x * j, y * i, 0});
                return;
            }
        }
        assert(false);
    };

    for(int i = 1; ; i++) {
        int y = x ^ (i * x);
        if(gcd(x, y) == 1) {
            mul(x, i);
            ans.push_back({x, i * x, 1});
            int cur = (x - 1) * (y - 1);
            if(cur & 1) cur += 1;
            make(x, y, cur);
            make(x, y, cur + 1);
            ans.push_back({cur, cur + 1, 1});
            break;
        }
    }

    cout << sz(ans) << endl;
    for(auto [x, y, c] : ans) cout << x << (c == 0 ? " + " : " ^ ") << y << endl;
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