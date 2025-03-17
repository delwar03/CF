#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

int fact[N], revFact[N], inv[N];

void solve() {
    int n, m, k; cin>>n>>m>>k;

    vector<int> degree(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        degree[u]++;
        degree[v]++;
    }

    auto nCr = [&] (int n, int r) {
        if(n < r) return 0LL;
        return (((fact[n] * revFact[r]) % mod) * revFact[n - r]) % mod;
    };

    int odd = 0;

    for(int i = 1; i <= n; i++) {
        odd += (degree[i] & 1);
    }

    int even = n - odd;

    int ans = 0;

    for(int i = 0; i <= k && i <= odd; i += 2) {
        ans = (ans + (nCr(odd, i) * nCr(even, k - i)) % mod) % mod;
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

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/