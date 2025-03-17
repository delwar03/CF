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
// const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int a, b, n, m, mod; cin>>a>>b>>n>>m>>mod;
    vector<vector<int>> mat = {{a, 1}, {0, 1}};

    auto matMult = [&] (vector<vector<int>> a, vector<vector<int>> b) {
        int n = sz(a);
        vector<vector<int>> ret(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    (ret[i][j] += (a[i][k] * b[k][j]) % mod) %= mod;
                }
            }
        }

        return ret;
    };

    auto matPow = [&] (vector<vector<int>> mat, int n) {
        vector<vector<int>> ret = {{1, 0}, {0, 1}};
        while(n) {
            if(n & 1) ret = matMult(ret, mat);
            mat = matMult(mat, mat);
            n >>= 1;
        }
        return ret;
    };

    auto mm = matPow(mat, n);
    // for(auto i : mm) {
    //     for(auto j : i) cerr<<j<<" "; cerr<<endl;
    // }

    int ans = (((m * b) % mod) * mm[0][1]) % mod;
    int tmp = m * (m + 1) / 2;
    tmp %= mod;
    (ans += (mm[0][0] * tmp) % mod) %= mod;

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}