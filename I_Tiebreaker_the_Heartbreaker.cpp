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
    string s; cin >> s;
    int n = sz(s);
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        x += (i % 2 == 0 && s[i] == '1');
        y += (i % 2 == 1 && s[i] == '1');
    }

    if(n & 1) { // y's turn
        if(y + 1 - x > 5 - (n + 1) / 2) {
            cout << 1 << endl;
        } else if(y + (5 - n / 2) - 1 < x) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if(x + 1 - y > 5 - n / 2) {
            cout << 1 << endl;
        } else if(x + (5 - (n + 1) / 2) - 1 < y) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    }
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