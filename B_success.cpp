#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int a, b, c; cin>>a>>b>>c;
    int x = min({a, b, c});
    int y = max({a, b, c});
    // int sum = a + c;
    // if(sum & 1) {cout<<"No"<<endl; return;}
    if((b >= a && b <= c) || (b <= a && b >= c)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 