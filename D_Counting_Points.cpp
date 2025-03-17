#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
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
    int n, m; cin>>n>>m;
    vector<int> X(n), R(n);
    for(auto &x : X) cin>>x;
    for(auto &x : R) cin>>x;

    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        int x = X[i], r = R[i];
        for(int j = x - r; j <= x + r; j++) {
            mp[j] = max(mp[j], (int) sqrtl(r * r - (x - j) * (x - j)));
        }
    }

    int ans = 0;
    for(auto [a, b] : mp) ans += 2 * b + 1;

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}