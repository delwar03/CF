#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t
// #define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
// const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() ^ getpid());

void solve() {
    int n, s, x; cin>>n>>s>>x;

    auto ask = [&] (int i) {
        cout<<"? "<<i<<endl;
        int val, nxt; cin>>val>>nxt;
        return pii{val, nxt};
    };

    auto ans = [&] (int x) {
        cout<<"! "<<x<<endl;
    };

    pii mx = {-1, -1};
    vector<int> vis(n + 1);
    auto [val, nxt] = ask(s);
    if(mx.F < val && val < x) {
        mx = max(mx, {val, s});
    } else {
        ans(val); return;
    }
    
    vis[s] = 1;

    for(int i = 1; i < min(1000, n); i++) {
        int id = rng() % n + 1;
        while(vis[id]) id = rng() % n + 1;
        auto [val, nxt] = ask(id);
        if(mx.F < val && val < x) {
            mx = max(mx, {val, id});
        }
        vis[id] = 1;
    }
    int cur = mx.S, ct = 0;
    while(~cur && ct++ < 999) {
        auto [val, nxt] = ask(cur);
        if(val >= x) {ans(val); return; }
        cur = nxt;
    }
    ans(-1);
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