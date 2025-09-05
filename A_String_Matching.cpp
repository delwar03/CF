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
const int mod = 998244353;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pp = 131;
int pw[N];

void solve() {
    string s, p; cin >> s >> p;
    int n = sz(s), m = sz(p);
    s = "#" + s, p = "#" + p;
    vector<int> pf(n + 1);
    for(int i = 1; i <= n; i++) pf[i] = (pf[i - 1] * pp + (s[i] - 'a' + 1)) % mod;

    auto getHash = [&] (int l, int r) {
        int ret = (pf[r] - (pf[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
        return ret;
    };

    int cur = 0;
    for(int i = 1; i <= m; i++) cur = (cur * pp + (p[i] - 'a' + 1)) % mod;

    int cnt = 0;
    for(int i = m; i <= n; i++) {
        if(getHash(i - m + 1, i) == cur) cnt += 1;
    }

    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = pw[i - 1] * pp % mod;

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}