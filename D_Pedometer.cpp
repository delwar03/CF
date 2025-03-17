#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
// const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, mod; cin>>n>>mod;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> pf(n + 1);
    for(int i = 0; i < n; i++) {
        pf[i + 1] = pf[i] + v[i];
    }
    for(int i = 0; i <= n; i++) pf[i] %= mod;

    map<int, int> mp;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += mp[pf[i]];
        mp[pf[i]]++;
    }

    mp.clear();
    // mp[0] = 1;

    for(int i = 1; i <= n; i++) {
        ans += mp[pf[i]];
        mp[(pf[n] + pf[i]) % mod]++;
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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