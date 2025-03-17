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
    int n; cin>>n;
    int ans = 0;

    function<int(int)> inv = [&] (int a) {
        return (a <= 1 ? a : mod - (mod / a) * inv(mod % a) % mod);
    };

    auto sum = [&] (int n) {
        return ((((__int128) n * (n + 1)) % mod) * inv(2)) % mod;
    };

    for(int i = 1; i <= n; ) {
        int q = n / i, last = n / q;
        (ans += ((__int128) ((sum(last) - sum(i - 1) + mod) % mod) * q) % mod) %= mod;
        i = last + 1;
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