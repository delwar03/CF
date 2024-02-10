#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int a, b, c; cin>>a>>b>>c;
    // int x = (b + c - 1) / c;
    int ans = a;
    while(1) {
        ans += c;
        if(ans > a + b) {cout<<ans<<endl; return;}
    }
    // cout<<a + c<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 