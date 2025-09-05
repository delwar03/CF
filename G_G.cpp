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
    vector<array<int, 4>> v(n);
    for(auto &[cx, cy, tx, ty] : v) cin >> cx >> cy >> tx >> ty;

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0LL);

    int ans = INF;
    do {
        int cur = 0, x = 0, y = 0;
        for(int i : ord) {
            cur += abs(x - v[i][2]) + abs(y - v[i][3]);
            x = v[i][2], y = v[i][3];
            cur += abs(x - v[i][0]) + abs(y - v[i][1]);
            x = v[i][0], y = v[i][1];
        }
        // cur += abs(x) + abs(y);
        cerr << "cur: " << cur << endl;
        ans = min(ans, cur);
    } while(next_permutation(ord.begin(), ord.end()));

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