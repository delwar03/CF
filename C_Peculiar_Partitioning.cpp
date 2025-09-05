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
const int N = 4e6 + 10;
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int sm = 0;
    for(auto &x : v) cin >> x, sm += x;

    int p = -1;
    for(int i = 2; i * i <= sm; i++) if(sm % i == 0) {p = i; break; }
    if(p == -1) {cout << "No" << endl; return; }

    if(p < n) {
        vector<int> last(p, -2);
        last[0] = -1;
        int pf = 0;
        for(int i = 0; i < n; i++) {
            (pf += v[i]) %= p;
            if(last[pf] != -2) {
                cout << "Yes" << endl;
                cout << i - last[pf] << endl;
                for(int j = last[pf] + 1; j <= i; j++) cout << j + 1 << " \n"[j == i];
                return;
            }
            last[pf] = i;
        }
    }

    vector<bitset<N>> dp(n + 1);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) dp[i] = dp[i - 1] | (dp[i - 1] << v[i - 1]);

    p = -1;
    for(int i = 1; i < sm; i++) {
        if(dp[n][i] && gcd(sm, i) > 1) {
            p = i; break;
        }
    }
    if(p == -1) {cout << "No" << endl; return; }

    vector<int> ord;
    for(int i = n; i > 0; i--) {
        if(!p) break;
        if(!dp[i - 1][p]) ord.push_back(i), p -= v[i - 1];
    }

    reverse(ord.begin(), ord.end());
    cout << "Yes" << endl;
    cout << sz(ord) << endl;
    for(int i = 0; i < sz(ord); i++) cout << ord[i] << " \n"[i == sz(ord) - 1];
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