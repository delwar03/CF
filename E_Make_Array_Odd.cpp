#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;

void solve() {
    int n, x; cin>>n>>x;
    int e = 0, f = 1;
    for(int i = 0; i < n; i++) {
        int p; cin>>p;
        if(p % 2 == 0) e++;
        else f = 0;
    }
    if(f) {
        if(x % 2 == 0) cout<<-1<<endl;
        else {
            cout<<(e + 1) / 2<<endl;
        }
    }
    else {
        if(x % 2 == 0) cout<<e<<endl;
        else cout<<(e + 1) / 2<<endl;
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