#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n, x, y; cin>>n>>x>>y;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int ans = 0;
    map<vector<int>, int> mp;
    for(auto it : v) {
        int p = (x - it % x) % x;
        int q = it % y;
        ans += mp[{p, q}];
        mp[{it % x, it % y}]++;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 