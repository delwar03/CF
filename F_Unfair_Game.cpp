#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 205;
const int INF = 1e15 + 10;

void solve() {
    int a, b, c, d; cin>>a>>b>>c>>d;

    int ans = (a / 2) + (b / 2) + (c / 2) + (d / 2);
    ans += (a * b * c) % 2;
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