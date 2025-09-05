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
    vector<string> a(n);
    for(auto &x : a) cin>>x;
    vector b(m, vector<string>(n));
    for(auto &x : b) for(auto &y : x) cin>>y;

    int ans = INF;
    for(auto c : b) {
        int ct = 0;
        for(int i = 0; i < n; i++) ct += a[i] != c[i];
        ans = min(ans, n + 2 * ct);
    }
    for(int i = 0; i < n; i++) {
        int f = 1;
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j][i]) f = 0;
        }
        if(f) ans = -1;
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