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
    int n, q; cin>>n>>q;
    vector<int> g[n + 1], val(n + 1);
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> st(n + 1), en(n + 1);
    int timer = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {
        st[u] = ++timer;
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u);
            }
        }
        en[u] = timer;
    };

    dfs(1, 0);

    int sz = 4 * n;

    vector<int> BIT(sz + 1);

    auto add = [&] (int x, int val) {
        for(int i = x; i <= sz; i += i & -i) BIT[i] += val;
    };

    auto sum = [&] (int x) {
        int ret = 0;
        for(int i = x; i; i -= i & -i) ret += BIT[i];
        return ret;
    };

    auto qur = [&] (int l, int r) {
        if(l > r) return 0LL;
        return sum(r) - sum(l - 1);
    };

    for(int i = 1; i <= n; i++) add(st[i], val[i]);

    while(q--) {
        int typ; cin>>typ;
        if(typ == 1) {
            int u, x; cin>>u>>x;
            add(st[u], -val[u] + x);
            val[u] = x;
        } else {
            int u; cin>>u;
            cout<<qur(st[u], en[u])<<endl;
        }
    }
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