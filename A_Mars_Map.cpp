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
    int n; cin >> n;
    vector<array<int, 4>> v(n);
    multiset<pii> all;
    int mx = 0;
    for(auto &[x1, y1, x2, y2] : v) cin >> x1 >> y1 >> x2 >> y2, mx = max(mx, x2), all.insert({x1, -1}), all.insert({x2, +1});

    vector<array<int, 3>> pos[mx + 1];
    for(auto [x1, y1, x2, y2] : v) {
        pos[x1].push_back({y1, y2, -1});
        pos[x2].push_back({y1, y2, +1});
    }

    multiset<int> st;
    int ans = 0;

    for(auto [x, f] : all) {
        auto it = all.lower_bound({x, -2});
        if(it != all.begin()) {
            --it;
            if(sz(st))
                ans += (x - (*it).F) * ((*(--st.end())) - (*st.begin()));
        }

        if(f == -1) {
            for(auto [y1, y2, ff] : pos[x]) if(ff == -1) {
                st.insert(y1), st.insert(y2);
            }
        } else {
            for(auto [y1, y2, ff] : pos[x]) if(ff == +1) {
                st.erase(st.find(y1)), st.erase(st.find(y2));
            }
        }
    }

    cout << ans << endl;
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