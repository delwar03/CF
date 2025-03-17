#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

int Inv[N], Fact[N], revFact[N];

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    sort(v.begin(), v.end());

    auto nCr = [&] (int n, int r) {
        if(n < r) return 0LL;
        return (((Fact[n] * revFact[r]) % mod) * revFact[n - r]) % mod;
    };

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = (ans + (v[i] * (nCr(i, k / 2) * nCr(n - i - 1, k / 2)) % mod) % mod) % mod; 
        // cerr<<ans<<endl;
    }

    cout<<ans<<endl;
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Inv[1] = 1;
    for(int i = 2; i < N; i++) {
        Inv[i] = mod - (mod / i) * Inv[mod % i] % mod;
    }

    Fact[0] = revFact[0] = 1;

    for(int i = 1; i < N; i++) {
        Fact[i] = (i * Fact[i - 1]) % mod;
        revFact[i] = (Inv[i] * revFact[i - 1]) % mod;
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