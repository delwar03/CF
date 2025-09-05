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
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int ans = INF, sm = 0, cur = 0, f = 1;
    for(int x : v) { // + -
        sm += x;
        if(f) {
            if(sm <= 0) cur += abs(sm) + 1, sm = 1;
        } else {
            if(sm >= 0) cur += abs(sm) + 1, sm = -1;
        }
        f ^= 1;
    }
    ans = cur;
    sm = cur = f  = 0;
    for(int x : v) { // - +
        sm += x;
        if(f) {
            if(sm <= 0) cur += abs(sm) + 1, sm = 1;
        } else {
            if(sm >= 0) cur += abs(sm) + 1, sm = -1;
        }
        f ^= 1;
    }

    ans = min(ans, cur);
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}