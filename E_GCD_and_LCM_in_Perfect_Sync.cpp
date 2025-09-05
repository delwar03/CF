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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int a1, n; cin>>a1>>n;

    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) (ret *= a) %= mod;
            (a *= a) %= mod;
            b >>= 1;
        }
        return ret;
    };

    auto get = [&] (int ct) {
        return (binPow(ct + 1, n) - 2 * binPow(ct, n) + binPow(ct - 1, n) + 2 * mod) % mod;
    };

    int ans = 1, tmp = a1;
    for(int i = 2; i * i <= tmp; i++) {
        if(tmp % i == 0) {
            int ct = 0;
            while(tmp % i == 0) ct++, tmp /= i;
            (ans *= get(ct)) %= mod;
        }
    }
    if(tmp > 1) (ans *= get(1)) %= mod;

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