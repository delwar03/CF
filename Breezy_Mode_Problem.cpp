#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, q; cin>>n>>q;
    map<int, int> mp;
    vector<int> v(n);
    int ans = 0;
    for(auto &x : v) {
        cin>>x;
        ans += ++mp[x];
    }

    while(q--) {
        int ind, x; cin>>ind>>x; --ind;
        
        ans -= mp[v[ind]]--;
        v[ind] = x;
        
        ans += ++mp[v[ind]];

        cout<<ans<<endl;
    }
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