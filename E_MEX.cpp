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
    string s; cin >> s;

    auto get = [&] (char ch) {
        if(ch == 'M') return 1;
        if(ch == 'E') return 2;
        if(ch == 'X') return 3;
        return 0;
    };

    int ans = 0;
    for(int m = 1; m <= 3; m++) {
        if(m != 3) continue;

        vector<int> pos[4];
        for(int i = 0; i < n; i++) if(v[i] ^ m && get(s[i])) pos[get(s[i])].push_back(i);

        vector<int> pf(n + 1);
        for(int i : pos[2]) {
            cerr << "i: " << i << endl;
            int id = lower_bound(pos[3].begin(), pos[3].end(), i) - pos[3].begin();
            pf[i] += sz(pos[3]) - id;
        }
        for(int i = 0; i <= n; i++) cerr << pf[i] << " "; cerr << endl;

        for(int i = 1; i <= n; i++) pf[i] += pf[i - 1];

        int cnt = 0;
        for(int i : pos[1]) {
            cnt += pf[n] - (i - 1 >= 0 ? pf[i - 1] : 0);
        }

        ans += m * cnt;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}