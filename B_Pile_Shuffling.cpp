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
    vector<int> a(n), b(n), c(n), d(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    priority_queue<pii> pq;
    for(int i = 0; i < n; i++) {
        pq.push({b[i] - d[i], i});
    }

    int ans = 0;
    while(sz(pq)) {
        auto [bd, i] = pq.top(); pq.pop();
        int ac = a[i] - c[i];
        if(bd > 0) {
            if(ac > 0) {
                ans += ac;
                ans += c[i] + bd;
            } else {
                ans += a[i] + bd;
            }
        } else {
            if(ac > 0) {
                ans += ac;
            } else {
                // 
            }
        }
    }

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