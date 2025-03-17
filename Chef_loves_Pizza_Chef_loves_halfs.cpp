#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 504;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

// 0 2

void solve() {
    int n; cin>>n;
    int m = n / 2;
    int base = 1;
    while(2 * base <= m) base <<= 1;

    // cerr<<base<<" "<<m<<endl;

    cout<<4 * (m - base)<<endl;
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