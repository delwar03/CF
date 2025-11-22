#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t
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

vector<int> di[N];

void solve() {
    int n; cin >> n;
    vector<int> val(n);
    for(auto &x : val) cin >> x;

    unordered_map<int, vector<int>> pos;
    for(int i = 0; i < n; i++) {
        for(int d : di[val[i]]) {
            pos[d].push_back(i);
        }
    }

    int ans = -1;

    for(auto [d, v] : pos) {
        for(int i = 0; i < sz(v); i++) {
            int j = i + 1, g = val[v[i]];
            while(j < sz(v) && v[j] == 1 + v[j - 1]) g = gcd(g, val[v[j++]]);
            if(g == d) ans = max(ans, j - i);
            i = j - 1;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        if(sz(di[i])) continue;
        for(int j = i; j < N; j += i) {
            di[j].push_back(i);
        }
    }

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}