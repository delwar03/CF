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
    int n; cin >> n;
    vector<int> a(n), b(n);
    int x1 = 0, x2 = 0;
    for(auto &x : a) cin >> x, x1 ^= x;
    for(auto &x : b) cin >> x, x2 ^= x;

    for(int i = 0; i < n; i++) if(a[i] ^ b[i]) {
        if(i % 2 == 0) {
            int dif = (x1 ^ a[i] ^ b[i]) - x1;
            if(dif > (x2 ^ a[i] ^ b[i]) - x2)
                x1 ^= a[i] ^ b[i], x2 ^= a[i] ^ b[i];
        } else {
            int dif = (x2 ^ a[i] ^ b[i]) - x2;
            if(dif > (x1 ^ a[i] ^ b[i]) - x1)
                x1 ^= a[i] ^ b[i], x2 ^= a[i] ^ b[i];
        }
    }

    cout << (x1 == x2 ? "Tie" : x1 > x2 ? "Ajisai" : "Mai") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}