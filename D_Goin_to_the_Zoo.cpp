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
    int n, m, pw = 1; cin>>n>>m;
    vector<int> v(n);
    for(auto &x : v) cin>>x, pw *= 3;
    vector<int> pos[n];
    for(int i = 0; i < m; i++) {
        int k; cin>>k;
        while(k--) {
            int x; cin>>x;
            --x;
            pos[x].push_back(i);
        }
    }

    int ans = INF;

    for(int i = 0; i < pw; i++) {
        int t = i, cur = 0;
        vector<int> vis(m);
        for(int j = 0; j < n; j++) {
            cur += (t % 3) * v[j];
            for(int k : pos[j]) vis[k] += (t % 3);
            t /= 3;
        }
        if(*min_element(vis.begin(), vis.end()) >= 2) ans = min(ans, cur);
    }

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