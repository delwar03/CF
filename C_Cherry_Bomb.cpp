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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    int mx = 0, mn = INF;
    for(auto &x : a) cin >> x, mx = max(mx, x), mn = min(mn, x);
    int cnt = 0;
    for(auto &x : b) cin >> x, cnt += (x == -1);

    if(cnt == n) {
        int l = mx, r = k + mn;
        cout << r - l + 1 << endl;
    } else {
        int sm = 0;
        for(int i = 0; i < n; i++) if(b[i] != -1) {
            sm = a[i] + b[i]; break;
        }
        for(int i = 0; i < n; i++) {
            if(b[i] == -1) {
                int cur = sm - a[i];
                if(cur < 0 || cur > k) {cout << 0 << endl; return; }
            } else if(a[i] + b[i] != sm) {
                cout << 0 << endl; return;
            }
        }
        cout << 1 << endl;
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