#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    sort(a.begin(), a.end());

    int difGCD = 0;
    for(int i = 1; i < n; i++) {
        difGCD = __gcd(difGCD, a[i] - a[0]);
    }

    
    for(auto it : b) {
        cout<<__gcd(difGCD, a[0] + it)<<" ";
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