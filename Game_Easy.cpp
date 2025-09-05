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
    int sm = 0;
    for(auto &x : v) cin >> x, sm += x;

    vector<pii> tmp;
    for(int i = 0; i < n; i++) tmp.push_back({v[i], i});
    sort(tmp.rbegin(), tmp.rend());

    // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2 * n + 1, -1)));

    // int cur = 0;

    // function<int(int, int, int)> magic = [&] (int i, int x, int rem) {
    //     if(i == n) return int(0);
    //     int &ans = dp[i][x][rem];
    //     if(~ans) return ans;
    //     ans = magic(i + 1, x, rem);
    //     if(rem - 1 >= 0) ans = max(ans, v[i] + magic(i + 1, x + 1, rem - 1));
    //     if(rem - 2 >= 0) ans = max(ans, v[i] + x + magic(i + 1, x + 1, rem - 2));
    //     return ans;
    // };

    auto sum = [&] (int l, int r) {
        return r * (r + 1) / 2 - l * (l - 1) / 2;
    };

    cerr << sm << endl;

    for(int i = 1; i <= 2 * n; i++) {
        priority_queue<pii> pq;
        int sm = 0, mx = 0;
        for(int j = 0; j < min(n, i); j++) pq.push({-tmp[j].F, tmp[j].S}), sm += tmp[j].F;
        int rem = max(0LL, i - sz(pq)), cur = sz(pq) - 1;
        if(rem) sm += sum(n - rem, n - 1), cur = n - rem - 1;
        mx = sm;
        // if(i == 7) cerr << cur << " " << sm << endl;
        int cnt = 1;
        while(sz(pq)) {
            auto [x, id] = pq.top(); pq.pop();
            x = -x;
            sm -= x;
            sm += cur - 1;
            mx = max(mx, sm);
            cur--; sm -= ++cnt;
            if(i == 8) cerr << sm << " " << mx << endl;
        }
        cout << mx << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}