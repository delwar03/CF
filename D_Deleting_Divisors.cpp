#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    if(n & 1) {
        cout<<"Bob"<<endl;
    } else {
        if(n & (n - 1)) { // not power of `2`
            cout<<"Alice"<<endl;
        } else { // power of `2`
            int pow = __lg(n);
            if(pow & 1) {
                cout<<"Bob"<<endl;
            } else {
                cout<<"Alice"<<endl;
            }
        }
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