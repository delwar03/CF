#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t
using ll = int64_t;
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
    int n, m, q; cin >> n >> m >> q;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    unordered_map<int, ll> mp;
    for(int i = 1; i * i <= m; i++) if(m % i == 0) mp[i] = mp[m / i] = 0;

    auto get = [&] (int x, int md) {
        x %= md;
        return x < 0 ? x + md : x;
    };

    for(auto &[a, b] : mp) {
        for(int i = 0; i < n; i++) {
            b += get(v[i] - (i - 1 >= 0 ? v[i - 1] : 0), a);
        }
    }

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int i, x; cin >> i >> x;
            --i;
            for(auto &[a, b] : mp) {
                b -= get(v[i] - (i - 1 >= 0 ? v[i - 1] : 0), a);
                b += get(x - (i - 1 >= 0 ? v[i - 1] : 0), a);

                if(i + 1 < n) {
                    b -= get(v[i + 1] - v[i], a);
                    b += get(v[i + 1] - x, a);
                }
            }
            v[i] = x;
        } else {
            int k; cin >> k;
            cout << (mp[gcd(k, m)] < m ? "YES" : "NO") << endl;
        }
    }
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