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
const int mod = 1e9 + 33;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pp = 31;
int pw[N];

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    for(int i = n - 1; i > 0; i--) a[i] = a[i] - a[i - 1];
    for(int i = m - 1; i > 0; i--) b[i] = b[i] - b[i - 1];

    for(auto &x : a) x += INF;
    for(auto &x : b) x += INF;
    
    vector<int> pf(n + 1);
    for(int i = 1; i <= n; i++) {
        pf[i] = (pf[i - 1] * pp + a[i - 1]) % mod;
    }
    int cur = 0;
    for(int i = 1; i < m; i++) cur = (cur * pp + b[i]) % mod;

    auto getHash = [&] (int l, int r) {
        return (pf[r] - (pf[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
    };

    int cnt = 0;
    for(int i = m - 1; i <= n; i++) {
        if(getHash(i - (m - 1) + 1, i) == cur) cnt += 1;
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