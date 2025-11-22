#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int unsigned long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 10;
const int INF = 1e18 + 10;
const int p = 37;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pw[N];

void solve() {
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(auto &x : v) cin >> x;

    unordered_map<int, int> mp;

    int ans = 0;

    for(auto s : v) {
        int cur = 0;
        for(int i = 0; i < m; i++) cur += (s[i] - 'a' + 1) * pw[i];
        
        for(int i = 0; i < m; i++) {
            for(int k = 1; k <= 26; k++) if(k != (s[i] - 'a' + 1)) {
                int now = cur + (k - (s[i] - 'a' + 1)) * pw[i];
                if(mp.count(now)) ans += mp[now];
            }
        }

        mp[cur]++;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = pw[i - 1] * p;

    int t = 1; // cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr << "Case " << tc << ": \n";
        solve();
    }
}