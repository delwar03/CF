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
    int n, q, ff = 0; cin >> n >> q;
    set<int> cuts = {0, n};
    o_set<pii> st;
    st.insert({n, ff++});

    while(q--) {
        char op; int x; cin >> op >> x;
        if(op == 'C') {
            auto it = cuts.lower_bound(x);
            if(*it == x) continue;
            auto prv = prev(it);
            st.erase(st.lower_bound({*it - *prv, 0}));
            st.insert({x - *prv, ff++});
            st.insert({*it - x, ff++});
            cuts.insert(x);
        } else {
            cout << st.find_by_order(x - 1)->F << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":\n";
        solve();
    }
}