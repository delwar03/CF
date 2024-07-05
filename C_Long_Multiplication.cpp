#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    string a, b; cin>>a>>b;
    int n = a.size();
    string x, y;
    for(int i = 0; i < n; i++) {
        char mx = max(a[i], b[i]);
        char mn = min(a[i], b[i]);
        if(x > y) {
            x += mn;
            y += mx;
        } else {
            x += mx;
            y += mn;
        }
    }
    cout<<x<<"\n"<<y<<endl;
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