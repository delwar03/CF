#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define pii pair<int, int>
#define sz(x) int(x.size())
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e9 + 10;

int fact[N], revFact[N], inv[N];

int nCr(int n, int r) {
    if(n < r || r < 0) return 0LL;
    return (((fact[n] * revFact[r]) % mod) * revFact[n - r]) % mod;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<pii> v(n);
    for(auto &[l, r] : v) cin >> l >> r;
    sort(v.begin(), v.end());

    multiset<int> st;
    int ans = 0;
    for(auto [l, r] : v) {
        while(sz(st) && *st.begin() < l) st.erase(st.begin());
        st.insert(r);
        (ans += nCr(sz(st) - 1, k - 1)) %= mod;
    }

    cout << ans << endl;
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