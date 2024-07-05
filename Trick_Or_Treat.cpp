#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    map<int, int> mp;
    for(auto it : b) {
        mp[(m - it % m) % m]++;
    }
    // for(auto it : mp) cerr<<it.first<<" -> "<<it.second<<endl;
    int ans = 0;
    for(auto it : a) {
        ans += mp[it % m];
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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