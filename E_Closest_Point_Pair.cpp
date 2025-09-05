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
    vector<array<int, 3>> v;
    for(int i = 0, x, y; i < n; i++) cin >> x >> y, v.push_back({x, y, i});
    sort(v.begin(), v.end());
    int d = INF, j = 0;
    pii ans = {-1, -1};

    auto dist = [&] (const pii& A, const pii& B) {
        int dx = A.F - B.F, dy = A.S - B.S;
        return dx * dx + dy * dy;
    };

    multiset<array<int, 3>> st;

    for(auto [x, y, i] : v) {
        int sd = sqrtl(d);
        while(j < n && v[j][0] < x - sd) st.erase(st.find({v[j][1], v[j][0], v[j][2]})), j++;
        auto it1 = st.lower_bound({y - sd, 0}), it2 = st.upper_bound({y + sd, INF});
        for(auto it = it1; it != it2; it++) {
            int cur = dist({(*it)[1], (*it)[0]}, {x, y});
            if(cur < d) {
                d = cur;
                ans.F = min((*it)[2], i), ans.S = max((*it)[2], i);
            }
        }
        st.insert({y, x, i});
    }
    cout << fixed << setprecision(6);
    cout << ans.F << " " << ans.S << " " << sqrt(d) << endl;
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