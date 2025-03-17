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
    n %= mod;
    if(k == 1) {cout<<n<<endl; return; }
    int a = 1, b = 1;
    for(int i = 3; i <= 6 * k + 10; i++) {
        a ^= b ^= a ^= b;
        (b += a) %= k;
        if(b == 0) {cout<<((n * i) % mod)<<endl; return;}
    }
    assert(false);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int sz = 1000, md = 109;
    // vector<int> fib(sz);
    // fib[0] = fib[1] = 1;
    // for(int i = 2; i < sz; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % md;

    // for(int i = 0; i < sz; i++) if(!fib[i]) cerr<<i + 1<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}