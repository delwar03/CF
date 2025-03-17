#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int fact[N], revFact[N], inv[N];

int nCr(int n, int r) {
    if(n < r || r < 0) return 0LL;
    return (((fact[n] * revFact[r]) % mod) * revFact[n - r]) % mod;
}

void solve() {
    int n, k; cin>>n>>k;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int l, r; cin>>l>>r;
        mp[l]++, mp[r + 1]--;
    }

    vector<int> cur;
    for(auto it : mp) cur.push_back(it.first);
    int ans = 0, cnt = 0;

    for(int i = 0; i < (int) cur.size() - 1; i++) {
        cnt += mp[cur[i]];
        if(cnt >= k)
            ans += (nCr(cnt, k) * (cur[i + 1] - cur[i])) % mod;
        ans %= mod;
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