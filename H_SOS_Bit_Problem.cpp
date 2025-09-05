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
const int N = 2e6 + 10;
// const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    for(auto &x : v) cin >> x, mx = max(mx, x);

    int k = 0;
    while((1 << k) <= mx) k++;

    int MX = 1 << k;
    vector<int> cnt(MX);
    for(int x : v) cnt[x]++;

    auto sub = cnt;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < MX; j++) if(j >> i & 1) {
            sub[j] += sub[j ^ (1LL << i)];
        }
    }

    auto sup = cnt;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < MX; j++) if(!(j >> i & 1)) {
            sup[j] += sup[j | (1LL << i)];
        }
    }

    for(int x : v) {
        int tmp = MX - 1;
        tmp &= (tmp ^ x);
        cout << sub[x] << " " << sup[x] << " " << n - sub[tmp] << endl;
    }
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