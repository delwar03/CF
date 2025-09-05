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
    int n; cin>>n;
    vector<pii> v(n);
    multiset<int> X, Y;
    for(auto &[a, b] : v) cin>>a>>b, X.insert(a), Y.insert(b);

    if(n == 1) {cout<<1<<endl; return; }

    int ans = INF;
    for(auto [a, b] : v) {
        X.erase(X.find(a));
        Y.erase(Y.find(b));
        int mn_x = *X.begin(), mx_x = *X.rbegin();
        int mn_y = *Y.begin(), mx_y = *Y.rbegin();
        int dx = mx_x - mn_x + 1, dy = mx_y - mn_y + 1;
        if(dx * dy == n - 1) {
            ans = min(ans, dx * (dy + 1));
            ans = min(ans, (dx + 1) * dy);
        } else {
            ans = min(ans, dx * dy);
        }
        X.insert(a);
        Y.insert(b);
    }

    cout<<ans<<endl;
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