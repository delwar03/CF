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
    int n; cin>>n;
    vector<int> v(n);
    int sm = 0;
    for(auto &x : v) cin>>x, sm += x;
    sort(v.begin(), v.end());

    int q; cin>>q;
    while(q--) {
        int x, y; cin>>x>>y;
        int id = lower_bound(v.begin(), v.end(), x) - v.begin();
        if(id == n) {
            int ans = x - v.back(), cur = sm - v.back();
            cout<<ans + max(0LL, y - cur)<<endl;
        } else {
            int cur = sm - v[id];
            int ans = max(0LL, y - cur);
            if(id - 1 >= 0) {
                id--;
                cur = sm - v[id];
                ans = min(ans, x - v[id] + max(0LL, y - cur));
            }
            cout<<ans<<endl;
        }
    }
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