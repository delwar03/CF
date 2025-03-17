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
    int n, l, r, x; cin>>n>>l>>r>>x;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    // for(int x : v) cerr<<x<<" "; cerr<<endl;

    int ans = 0;
    for(int i = 0; i < (1LL << n); i++) {
        if(__builtin_popcountll(i) < 2) continue;
        int sm = 0, mx = -INF, mn = INF;
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) {
                sm += v[j];
                mx = max(mx, v[j]);
                mn = min(mn, v[j]);
            }
        }

        // cerr<<sm<<" "<<mx<<" "<<mn<<endl;

        ans += (l <= sm && sm <= r && mx - mn >= x);
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}