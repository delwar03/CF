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

int Fact[N], rFact[N], Inv[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.begin(), v.end());

    auto nCr = [&] (int n, int r) {
        return (Fact[n] * rFact[r] % mod) * rFact[n - r] % mod;
    };

    int ans = v[0];
    for(int i = 1; i < n; i++) (ans += nCr(i + v[i], i + 1)) %= mod;
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < N; i++) {
        Inv[i] = (i <= 1 ? i : mod - (mod / i) * Inv[mod % i] % mod);
        Fact[i] = (i == 0 ? 1 : Fact[i - 1] * i % mod);
        rFact[i] = (i == 0 ? 1 : rFact[i - 1] * Inv[i] % mod);
    }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}