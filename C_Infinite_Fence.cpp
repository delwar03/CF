#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int r, b, k; cin>>r>>b>>k;
    if(r < b) swap(r, b);
    int g = __gcd(r, b);
    r /= g; b /= g;
    cout<<(1 + (k - 1) * b < r ? "REBEL" : "OBEY")<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/