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
const int mod = 1000000007;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Fact[N], rFact[N], Inv[N];

int nCr(int n, int r) {
    if(n < r) return 0;
    return (Fact[n] * rFact[r] % mod) * rFact[n - r] % mod;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> freq(26);
    for(auto c : s) freq[c - 'a']++;

    int ans = 1;
    for(int i = 0; i < 26; i++) if(freq[i]) {
        int cur = 0;
        for(int j = 0; j <= freq[i]; j += 2) (cur += nCr(freq[i], j)) %= mod;
        ans = ans * cur % mod;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Fact[0] = rFact[0] = Inv[1] = 1;
    for(int i = 2; i < N; i++) Inv[i] = mod - (mod / i) * Inv[mod % i] % mod;
    for(int i = 1; i < N; i++) {
        Fact[i] = Fact[i - 1] * i % mod;
        rFact[i] = rFact[i - 1] * Inv[i] % mod;
    }

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}