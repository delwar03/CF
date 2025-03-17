#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int N = 3e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Fact[N], revFact[N], Inv[N];

int nCr(int n, int r) {
    if(n < r || r < 0) return 0LL;
    return (((Fact[n] * revFact[r]) % mod) * revFact[n - r]) % mod;
}

int binPow(int a, int b) {
    int ret = 1;
    while(b > 0) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

int inv(int n) {
    return binPow(n, mod - 2);
}

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    int sm = 0;

    for(int i = 0; i < n; i++) {
        sm += a[i] + b[i];
        sm %= mod;
    }

    for(int t = 1; t <= n; t++) {
        int ans = 0;

        int tmp = nCr(n - 1, t - 1);

        ans = (tmp * sm) % mod;

        // cerr<<ans<<endl;

        ans = (ans * inv(nCr(n, t))) % mod;
        ans = (ans * inv(2)) % mod;

        cout<<ans<<" \n"[t == n];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Inv[1] = Fact[0] = revFact[0] = 1;

    for(int i = 2; i < N; i++) {
        Inv[i] = mod - (mod / i) * Inv[mod % i] % mod;
    }

    for(int i = 1; i < N; i++) {
        Fact[i] = (Fact[i - 1] * i) % mod;
        revFact[i] = (revFact[i - 1] * Inv[i]) % mod;
    }

    // vector<int> tmp = {1, 2, 3, 4, 5};

    // int x = 0;
    // for(int i = 0; i < 5; i++) 
    //     for(int j = i + 1; j < 5; j++) 
    //         for(int k = j + 1; k < 5; k++)
    //             x += tmp[i] + tmp[j] + tmp[k];

    // cerr<<"x: "<<x<<endl;

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}