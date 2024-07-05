#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 205;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    int mx = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        sum += x;
        if(sum < 0) {
            mx = max(mx, -sum);
        }
    }
    // cerr<<"sum: "<<sum<<endl;
    // cerr<<"mx: "<<mx<<endl;
    cout<<mx + sum<<endl;
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