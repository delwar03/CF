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
    int n, k; cin >> n >> k;
    vector<int> v(n), freq(n + 1), p(n + 1), pos[n + 1];
    for(auto &x : v) cin >> x, freq[x]++;
    for(int i = 0; i < n; i++) pos[v[i]].push_back(i);
    for(int i = 1; i <= n; i++) {
        if(freq[i] % k) {cout << 0 << endl; return; }
        p[i] = freq[i] / k;
    }

    vector<int> prv(n + 1);
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++) {
        prv[v[i]]++;
        while(prv[v[i]] > p[v[i]]) prv[v[j++]]--;
        ans += (i - j + 1);
    }
    
    cout << ans << endl;
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