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
const int INF = 8e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector<pii> v(n);
    for(auto &[x, y] : v) cin >> x >> y;
    sort(v.begin(), v.end());

    auto dist = [&] (const pii& A, const pii& B) {
        int dx = A.F - B.F, dy = A.S - B.S;
        return dx * dx + dy * dy;
    };

    multiset<pii> st; // {y, x}
    int mn = INF, j = 0;
    for(auto [x, y] : v) {
        int d = sqrtl(mn);
        while(v[j].F < x - d) st.erase(st.find({v[j].S, v[j].F})), j++;
        auto it1 = st.lower_bound({y - d, 0}), it2 = st.upper_bound({y + d, INF});
        for(auto it = it1; it != it2; it++) {
            mn = min(mn, dist(pii{it->S, it->F}, pii{x, y}));
        }
        st.insert({y, x});
    }
    cout << mn << endl;
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