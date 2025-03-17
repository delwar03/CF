#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int ans = 0, prv = 0;

    for(int i = 0; i < n; i++) {
        int cur = min(prv, v[i] / 2);
        ans += cur;
        prv -= cur;
        v[i] -= 2 * cur;

        ans += v[i] / 3; // (2^i, 2^i, 2^i)
        v[i] %= 3;
        
        prv += v[i];
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