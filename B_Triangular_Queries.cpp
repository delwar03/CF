#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
// const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[3 * N], cnt[3 * N], BIT_X[N], BIT_Y[N];
vector<array<int, 3>> qur[N];

void solve() {
    int n, q; cin >> n >> q;
    vector<pii> v(n);
    for(auto &[x, y] : v) cin >> x >> y, cnt[x + y] += 1;
    for(int i = 1; i < N; i++) dp[i] = dp[i - 1] + cnt[i];

    auto add = [&] (int x, int val, int f) {
        if(x <= 0) return;
        for(int i = x; i < N; i += i & -i) (f ? BIT_X[i] : BIT_Y[i]) += val;
    };

    auto sum = [&] (int x, int f) {
        int ret = 0;
        for(int i = x; i > 0; i -= i & -i) ret += (f ? BIT_X[i] : BIT_Y[i]);
        return ret;
    };

    for(auto [x, y] : v) add(x, +1, 1), add(y, +1, 0);

    for(int i = 0; i < q; i++) {
        int x, y, d; cin >> x >> y >> d;
        qur[x].push_back({y, d, i});
    }

    multiset<int> st;
    vector<int> ans(q);

    for(int x = 1; x < N; x++) {
        for(auto [y, d, i] : qur[x]) {
            int id = distance(st.begin(), st.lower_bound(y));
            // cerr << x << " " << y << " " << d << " " << id << endl;
            ans[i] = dp[x + y + d] - sum(x - 1, 1) - sum(y - 1, 0) + id;
        }
        for(auto [y, d, i] : qur[x]) st.insert(y);
    }

    for(int i = 0; i < q; i++) cout << ans[i] << endl;
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