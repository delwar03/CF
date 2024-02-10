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
    int n; cin>>n;
    int t = 0, a = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        t += x;
        a += y;
    }
    if(t > a) cout<<"Takahashi"<<endl;
    else if(a > t) cout<<"Aoki"<<endl;
    else cout<<"Draw"<<endl;
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