#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

int fact[N], revFact[N], inv[N];

int nCr(int n, int r) {
    if(n < r || r < 0) return 0LL;
    return (((fact[n] * revFact[r]) % mod) * revFact[n - r]) % mod;
}

void solve() {
    int n; cin>>n;
    for(int k = 1; k <= (n - 1) / 2; k++) {
        int ans = 0;
        for(int i = k + 1; n - i >= k; i++) {
            (ans += (nCr(i - 1, k) * nCr(n - i, k)) % mod) %= mod;
            if(k == 1)
                cerr<<"ans: "<<ans<<endl;
        }
        cout<<ans<<" ";
    } cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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