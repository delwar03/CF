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
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n)), c(n, vector<int>(n)), x(n, vector<int>(1));
    for(auto &x : a) for(auto &y : x) cin>>y;
    for(auto &x : b) for(auto &y : x) cin>>y;
    for(auto &x : c) for(auto &y : x) cin>>y;

    for(int i = 0; i < n; i++) x[i][0] = rng() % mod;

    auto matMult = [&] (vector<vector<int>>& a, vector<vector<int>>& b) {
        int x = sz(a), y = sz(b), z = sz(b[0]);
        vector<vector<int>> ret(x, vector<int>(z, 0));
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < z; j++) {
                for(int k = 0; k < y; k++) {
                    (ret[i][j] += a[i][k] * b[k][j] % mod) %= mod;
                }
            }
        }
        return ret;
    };

    auto am = matMult(b, x);
    am = matMult(a, am);
    auto cm = matMult(c, x);

    cout<<(am == cm ? "YES" : "NO")<<endl;
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