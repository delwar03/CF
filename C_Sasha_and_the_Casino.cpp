#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int k, x, a; cin>>k>>x>>a;
    int prv = 1, aa = a;
    a--;
    for(int i = 1; i < x; i++) {
        int now = prv / (k - 1);
        now++;
        a -= now;
        prv += now;
        if(a < 0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    // cout<<"a: "<<a<<endl;
    if(a < 0) cout<<"NO"<<endl;
    else {
        a *= k;
        if(a > aa) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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