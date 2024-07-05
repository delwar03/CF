#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    int q; cin>>q;
    while(q--) {
        int r1, c1, r2, c2; cin>>r1>>c1>>r2>>c2;
        --r1; --c1; --r2; --c2;
        int val1 = a[r1] + b[c1];
        int val2 = a[r2] + b[c2];

        if((val1 + val2) & 1) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
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