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

bool isPrime(int n) {
    int d = n - 1, s = 0;
    while(d % 2 == 0) d /= 2, s++;

    auto binPow = [&] (int a, int b, int mod) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) ret = (__int128) ret * a % mod;
            a = (__int128) a * a % mod;
            b >>= 1;
        }
        return ret;
    };

    auto isCmp = [&] (int a, int s, int d, int mod) {
        int x = binPow(a, d, mod);
        if(x == 1 || x == mod - 1) return false;
        for(int i = 1; i < s; i++) {
            x = (__int128) x * x % mod;
            if(x == mod - 1) return false;
        }
        return true;
    };

    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(n == a) return true;
        if(isCmp(a, s, d, n)) return false;
    }
    return n >= 2;
}

void solve() {
    int n; cin>>n;
    cout<<(isPrime(n) ? "YES" : "NO")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}