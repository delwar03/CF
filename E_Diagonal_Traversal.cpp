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
    int n, m; cin >> n >> m;
    if(n == 1) {cout << (m == 1 ? "YES" : "NO") << endl; return; }
    cout << ((n + m) & 1 ? "NO" : "YES") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<pii> st;

    for(int i = 1; i <= 10000; i++) {
        for(int j = 1; j <= 10000; j++) {
            int sq = sqrt(i * i + j * j);
            if(sq * sq == i * i + j * j) {
                // cerr << i << " " << j << " " << sq <<  endl;
                int g = gcd(i, j), x = i / g, y = j / g;
                if(!st.count({x, y}) && !st.count({y, x})) st.insert({x, y});
            }
        }
    }

    cerr << sz(st) << endl;
    for(auto [x, y] : st) cerr << x << " " << y << endl;

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        cout<<"Case "<<tc<<": ";
        solve();
    }
}