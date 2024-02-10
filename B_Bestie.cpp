#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;


void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int g = 0;
    for(auto &x : v) {
        cin>>x;
        g = __gcd(g, x);
    }
    if(g == 1) {
        cout<<"0\n";
    } else if(__gcd(g, n) == 1) {
        cout<<"1\n";
    } else if(__gcd(g, n - 1) == 1) {
        cout<<"2\n";
    } else {
        cout<<"3\n";
    }
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