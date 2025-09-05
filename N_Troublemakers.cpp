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
    int n, m; cin>>n>>m;
    vector<pii> trb(m);
    for(auto &[a, b] : trb) cin>>a>>b, --a, --b;

    for(int iter = 0; iter < 1000; iter++) {
        vector<int> vis(n);
        for(int i = 0; i < n; i++) vis[i] = rng() % 2;
        int ct = 0;
        for(auto [a, b] : trb) ct += (vis[a] == vis[b]);
        if(ct <= m / 2) {
            cout<<accumulate(vis.begin(), vis.end(), 0LL)<<endl;
            for(int i = 0; i < n; i++) if(vis[i]) cout<<i + 1<<" "; cout<<endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        cout<<"Case #"<<tc<<": ";
        solve();
    }
}