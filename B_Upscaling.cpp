#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

string a = "##", b = "..";

void solve() {
    int n; cin>>n;
    string p = "", q = "";
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            p += a;
            q += b;
        } else {
            p += b;
            q += a;
        }
    }
    // cerr<<p<<" "<<q<<endl;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) cout<<p<<endl<<p<<endl;
        else cout<<q<<endl<<q<<endl;
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