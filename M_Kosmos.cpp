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
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define mat array<array<int, 2>, 2>

mat bse = {1, 1, 1, 0}, I = {1, 0, 0, 1};

mat matMult(mat& a, mat& b, int mod) {
    mat ret = {0, 0, 0, 0};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                (ret[i][j] += ((__int128) a[i][k] * b[k][j]) % mod) %= mod;
            }
        }
    }
    return ret;
}

mat matPow(mat a, int b, int mod) {
    auto ret = I;
    while(b > 0) {
        if(b & 1) ret = matMult(ret, a, mod);
        a = matMult(a, a, mod);
        b >>= 1;
    }
    return ret;
}

int binPow(int a, int b, int mod) {
    int ret = 1;
    while(b > 0) {
        if(b & 1) (ret *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n; cin>>n;

    auto pw = matPow(bse, n, mod - 1)[0][1];
    // cerr<<pw<<endl;

    cout<<binPow(2, pw, mod)<<endl;
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