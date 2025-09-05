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

int par[N], siz[N];

int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    if(siz[u] < siz[v]) swap(u, v);
    par[v] = u;
    siz[u] += siz[v];
    return true;
}

void solve() {
    int n; cin >> n;
    n--;
    for(int i = 0; i <= n; i++) par[i] = i, siz[i] = 1;
    int ans = 0;
    for(int mask = n - 1; mask > 0; mask--) {
        for(int i = 0; i < 20; i++) {
            int sup = mask | (1LL << i);
            if(sup <= n && join(sup, mask)) {
                ans += mask;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int sz = 3;

    // for(int i = 1; i <= sz; i++) {
    //     for(int j = i + 1; j <= sz; j++) {
    //         cerr << "i: " << i << " j: " << j << ", and: " << (i & j) << endl;
    //     }
    // }

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}