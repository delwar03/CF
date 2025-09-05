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

int dp[35][2][2][2];

void solve() {
    vector<pii> v(3);
    for(auto &[l, r] : v) cin>>l>>r;
    vector<int> cur(3);

    function<int(int, int, int, int)> magic = [&] (int id, int f1, int f2, int f3) {
        if(id < 0) return 1LL;
        int &ans = dp[id][f1][f2][f3];
        if(~ans) return ans;
        ans = 0;
        for(int x : {0, 1}) {
            for(int y : {0, 1}) {
                for(int z : {0, 1}) {
                    if(x ^ y ^ z) continue;
                    if(f1 && !(cur[0] >> id & 1) && x == 1) continue;
                    if(f2 && !(cur[1] >> id & 1) && y == 1) continue;
                    if(f3 && !(cur[2] >> id & 1) && z == 1) continue;
                    (ans += magic(id - 1, f1 && ((cur[0] >> id & 1) == x), f2 && ((cur[1] >> id & 1) == y), f3 && ((cur[2] >> id & 1) == z))) %= mod;
                }
            }
        }
        return ans;
    };

    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) (ret *= a) %= mod;
            (a *= a) %= mod;
            b >>= 1;
        }
        return ret;
    };

    auto inv = [&] (int a) {
        return binPow(a, mod - 2);
    };

    int num = 0, den = 1;

    for(auto [a, b] : v) {
        (den *= (b - a + 1)) %= mod;
    }

    // cerr<<"den: "<<den<<endl;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 3; j++) {
            cur[j] = (i >> j & 1 ? v[j].S : v[j].F - 1);
        }
        memset(dp, -1, sizeof dp);
        (num += ((__builtin_popcount(i) & 1) ? magic(32, 1, 1, 1) : -magic(32, 1, 1, 1) + mod)) %= mod;
    }

    (num *= inv(den)) %= mod;
    (num = 1 - num + mod) %= mod;
    cout<<num<<endl;
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