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
const int N = 2e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Fact[N], InvFact[N], Inv[N], D[N];

int nCr(int n, int r) {
    if(n < r) return 0;
    return (Fact[n] * InvFact[r] % mod) * InvFact[n - r] % mod;
}

void solve() {
    int n; cin>>n;
    if(n & 1) {
        int ans = (__int128) Fact[n] * D[n] % mod;
        cout<<ans<<endl;
    } else {
        cout<<1<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Fact[0] = InvFact[0] = Inv[1] = 1;
    for(int i = 2; i < N; i++) Inv[i] = mod - (mod / i) * Inv[mod % i] % mod;
    for(int i = 1; i < N; i++) Fact[i] = Fact[i - 1] * i % mod, InvFact[i] = InvFact[i - 1] * Inv[i] % mod;

    D[0] = 1, D[1] = 0;
    for(int i = 2; i < N; i++) D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % mod;

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}