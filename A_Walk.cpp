#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
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
    int n, k; cin>>n>>k;
    vector<vector<int>> v(n, vector<int>(n));
    for(auto &x : v) for(auto &y : x) cin>>y;

    auto matMult = [&] (vector<vector<int>> a, vector<vector<int>> b) {
        int x = sz(a), y = sz(a[0]), z = sz(b);
        vector<vector<int>> c(x, vector<int>(z));
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < z; j++) {
                for(int k = 0; k < y; k++) {
                    (c[i][j] += (a[i][k] * b[k][j]) % mod) %= mod;
                }
            }
        }
        return c;
    };

    auto matPow = [&] (vector<vector<int>> mat, int b) {
        auto ret = mat;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ret[i][j] = (i == j);
        while(b) {
            if(b & 1) ret = matMult(ret, mat);
            mat = matMult(mat, mat);
            b >>= 1;
        }
        return ret;
    };

    auto mm = matPow(v, k);
    
    int ans = 0;
    for(auto x : mm) {
        for(auto y : x) (ans += y) %= mod;
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}