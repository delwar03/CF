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
    int k, n; cin>>k>>n;
    vector<int> g[n];
    for(int i = 0; i < n; i++) {
        int l; cin>>l;
        while(l--) {
            int x; cin>>x;
            g[i].push_back(--x);
        }
    }

    if(n >= 5 * k + 10) {cout<<"possible"<<endl; return; }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0LL);
    while(double(clock()) / CLOCKS_PER_SEC < 0.9) {
        random_shuffle(ord.begin(), ord.end());
        vector<bool> vis(n);
        int cnt = 0;
        for(int i : ord) if(!vis[i]) {
            cnt += 1;
            vis[i] = 1;
            for(int j : g[i]) vis[j] = 1;
        }
        if(cnt >= k) {cout<<"possible"<<endl; return; }
    }
    cout<<"impossible"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(2333333);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}