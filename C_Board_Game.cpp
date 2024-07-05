#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    if(x1 <= x2 && y1 <= y2) {
        cout<<"Polycarp"<<endl;
    } else {
        int p = x1 + y1;
        int v_mn = max(x2, y2);
        if(p <= v_mn) {
            cout<<"Polycarp"<<endl;
        } else {
            cout<<"Vasiliy"<<endl;
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