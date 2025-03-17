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
const int N = 2e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Fact[N], rFact[N], Inv[N], Pf[N], rPf[N];

void solve() {
    int x, l, r; cin>>x>>l>>r;
    int ans = rPf[x];
    (ans *= (Pf[r] - (l - 1 >= 0 ? Pf[l - 1] : 0LL) + mod)) %= mod;
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Fact[0] = rFact[0] = Inv[1] = 1;
    for(int i = 1; i < N; i++) {
        if(i > 1) Inv[i] = mod - (mod / i) * Inv[mod % i] % mod;
        Fact[i] = (i * Fact[i - 1]) % mod;
        rFact[i] = (Inv[i] * rFact[i - 1]) % mod;
    }

    for(int i = 0; i < N; i++) {
        Pf[i] = ((i - 1 >= 0 ? Pf[i - 1] : 0) + Fact[i]) % mod;
        rPf[i] = ((i - 1 >= 0 ? rPf[i - 1] : 0) + rFact[i]) % mod;
    }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}