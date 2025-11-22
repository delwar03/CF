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

struct DSU {
    vector<int> par, siz;
    
    DSU(int n) {
        par = vector<int>(n + 1);
        siz = vector<int>(n + 1, 1);
        iota(par.begin(), par.end(), 0LL);
    }

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
};

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    DSU ds(n + 1);
    vector<pii> edges;
    set<int> st = {v[0]};
    for(int i = 1; i < n; i++) {
        auto it = st.upper_bound(v[i]);
        int mn = v[i];
        vector<int> del;
        if(it != st.begin()) {
            --it;
            while(it != st.begin()) {
                if(ds.join(v[i], *it)) {
                    edges.push_back({v[i], *it});
                    del.push_back(*it);
                }
                --it;
            }
            if(it == st.begin()) {
                if(ds.join(v[i], *it)) {
                    edges.push_back({v[i], *it});
                }
            }
        }
        for(int x : del) st.erase(x);
    }

    if(sz(edges) == n - 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}