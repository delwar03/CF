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
    vector<pii> pt(n + 1);
    vector<array<int, 3>> v;
    for(int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        v.push_back({abs(x), abs(y), i});
        pt[i] = {x, y};
    }
    sort(v.begin(), v.end());

    auto dist = [&] (const pii& A, const pii& B) {
        int dx = A.F - B.F, dy = A.S - B.S;
        return dx * dx + dy * dy;
    };

    int mn = INF, j = 0, a = -1, b = -1;
    multiset<array<int, 3>> st;

    for(auto [x, y, i] : v) {
        int d = sqrtl(mn);
        while(v[j][0] < x - d) st.erase({v[j][1], v[j][0], v[j][2]}), j++;
        auto it1 = st.lower_bound({y - d, 0, 0}), it2 = st.upper_bound({y + d, INF, INF});
        for(auto it = it1; it != it2; it++) {
            int dd = dist({x, y}, {(*it)[1], (*it)[0]});
            // cerr << mn << " " << dd << endl;
            if(dd < mn) {
                mn = dd;
                a = (*it)[2], b = i;
            }
        }
        st.insert({y, x, i});
    }

    auto get = [&] (int i, int f) {
        if(f) {
            if(pt[i].F > 0) {
                return pt[i].S > 0 ? 1 : 3;
            } else {
                return pt[i].S > 0 ? 2 : 4;
            }
        } else {
            if(pt[i].F > 0) {
                return pt[i].S > 0 ? 4 : 2;
            } else {
                return pt[i].S > 0 ? 3 : 1;
            }
        }
    };

    // cerr << "mn: " << mn << endl;

    cout << a << " " << get(a, 1) << " " << b << " " << get(b, 0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}