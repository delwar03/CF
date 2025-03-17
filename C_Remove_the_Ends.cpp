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
    for(auto &x : v) cin>>x;

    vector<int> pos(n), neg(n);

    for(int i = 0; i < n; i++) pos[i] = (i - 1 >= 0 ? pos[i - 1] : 0) + (v[i] > 0 ? v[i] : 0);
    for(int i = n - 1; i >= 0; i--) neg[i] = (i + 1 < n ? neg[i + 1] : 0) + (v[i] < 0 ? -v[i] : 0);

    // for(int i : pos) cerr<<i<<" "; cerr<<endl;
    // for(int i : neg) cerr<<i<<" "; cerr<<endl;

    int sm = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] > 0) sm += v[i];
        ans = max(ans, sm + neg[i]);
    }
    
    // cerr<<ans<<endl;
    
    sm = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] < 0) sm += -v[i];
        ans = max(ans, sm + pos[i]);
    }

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