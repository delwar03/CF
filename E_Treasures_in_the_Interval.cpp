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
    int n, q, m; cin >> n >> q >> m;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    vector<int> val(n);
    for(int i = 0; i < n; i++) {
        val[i] += v[i];
        if(i + 1 < n) val[i + 1] -= v[i];
    }
    for(int i = 0; i < q; i++) {
        int l, r, d; cin >> l >> r >> d; --l, --r;
        val[l] += d;
        if(r + 1 < n) val[r + 1] -= d;
    }

    for(int i = 1; i < n; i++) val[i] += val[i - 1];
    sort(val.rbegin(), val.rend());

    while(m--) {
        int id; cin >> id; --id;
        cout << val[id] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1 2 3 4 5
    // 11 12 13 4 5
    // 11 8 9 0 1
    // 11 8 9 0 101

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}