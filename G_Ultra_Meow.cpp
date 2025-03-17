#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

int fact[N], revFact[N], inv[N];

void solve() {

    int n; cin>>n;

    auto nCr = [&] (int n, int r) {
        if(n < r) return 0LL;
        return (((fact[n] * revFact[r]) % mod) * revFact[n - r]) % mod;
    };

    int ans = 0;

    for(int sz = 0; sz <= n; sz++) {
        for(int k = 1; k < 2 * n + 10; k++) { // our MEX = k
            int a = k - 1 - sz;
            int b = sz - a;
            if(min(a, b) >= 0) {
                ans += ((nCr(min(n, k - 1), a) * nCr(max(0LL, n - k), b) % mod) * k) % mod;
                ans %= mod;
            }
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    inv[1] = fact[0] = revFact[0] = 1;

    for(int i = 2; i < N; i++) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }

    for(int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        revFact[i] = (revFact[i - 1] * inv[i]) % mod;
    }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/