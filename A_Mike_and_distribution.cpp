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
    vector<int> a(n), b(n);
    int sm[2]{};
    for(auto &x : a) cin>>x, sm[0] += x;
    for(auto &x : b) cin>>x, sm[1] += x;

    int k = n / 2 + 1;
    for(int i = 0; i < 1500; i++) {
        vector<int> vis(n), cur(2);
        for(int i = 0; i < k; i++) {
            int id = rng() % n;
            while(vis[id]) id = rng() % n;
            cur[0] += a[id], cur[1] += b[id];
            vis[id] = 1;
        }
        if(2 * cur[0] > sm[0] && 2 * cur[1] > sm[1]) {
            cout<<k<<endl;
            for(int i = 0; i < n; i++) if(vis[i]) cout<<i + 1<<" "; 
            return;
        }
    }
    cout<<-1<<endl;
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