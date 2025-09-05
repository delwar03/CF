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
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    priority_queue<pii> pq;
    for(int i = 0; i < n; i++) pq.push({v[i], i});
    vector<int> ans(n);
    int r = 1;
    while(sz(pq)) {
        auto [x, i] = pq.top(); pq.pop();
        ans[i] = r;
        int cnt = 1;
        while(sz(pq) && pq.top().F == x) ans[pq.top().S] = r, cnt++, pq.pop();
        r += cnt;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << endl;
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