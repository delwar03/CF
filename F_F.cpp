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
    vector<int> v(n), cnt(30);
    int ans = 0;
    for(auto &x : v) {
        cin >> x, ans += x;
        for(int j = 0; j < 30; j++) {
            if(x >> j & 1) cnt[j]++;
        }
    }

    pii mx = {-INF, -INF};
    for(int i = 0; i < n; i++) {
        int ct = 0;
        for(int j = 0; j < 30; j++) {
            if(v[i] >> j & 1) {
                ct -= (1LL << j) * cnt[j];
                ct += (1LL << j) * (n - cnt[j]);
            } else {
                ct += (1LL << j) * cnt[j];
                ct -= (1LL << j) * (n - cnt[j]);
            }
        }
        mx = max(mx, {ct, v[i]});
    }
    
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += (v[i] ^ mx.S);
    }
    ans = max(ans, cur);
    cout << ans << endl;
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