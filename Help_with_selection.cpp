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

int fact[N], rev[N], inv[N];

void solve() {
    int n, k, p; cin>>n>>k>>p;

    vector<int> F(p + 1), R(p + 1), I(p + 1);

    F[0] = R[0] = I[1] = 1;
    for(int i = 1; i <= p; i++) {
        if(i > 1) I[i] = p - (p / i) * I[p % i] % p;
        F[i] = (F[i - 1] * i) % p;
        R[i] = (R[i - 1] * I[i]) % p;
    }

    auto nCr = [&] (int n, int r) {
        if(n < r) return 0LL;
        return (((F[n] * R[r]) % p) * R[n - r]) % p;
    };

    int ans = 1;
    while(n || k) {
        int nn = n % p, kk = k % p;
        (ans *= nCr(nn, kk)) %= p;
        n /= p; k /= p;
    }

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