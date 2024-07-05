#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);

    int x, y, z;
    int XOR1, AND1, XOR2, AND2, XOR3, AND3;

    cout<<"XOR "<<1<<" "<<2<<endl;
    cin>>XOR1;
    cout<<"AND "<<1<<" "<<2<<endl;
    cin>>AND1;
    x = XOR1 + 2 * AND1;

    cout<<"XOR "<<2<<" "<<3<<endl;
    cin>>XOR2;
    cout<<"AND "<<2<<" "<<3<<endl;
    cin>>AND2;
    y = XOR2 + 2 * AND2;

    XOR3 = XOR1 ^ XOR2;
    cout<<"AND "<<1<<" "<<3<<endl;
    cin>>AND3;
    z = XOR3 + 2 * AND3;

    v[1] = (x + z - y) / 2;
    v[2] = (x + y - z) / 2;
    v[3] = (y + z - x) / 2;

    for(int i = 4; i <= n; i++) {
        cout<<"XOR "<<1<<" "<<i<<endl;
        int val; cin>>val;
        v[i] = val;
    }

    for(int i = 4; i <= n; i++) v[i] ^= v[1];

    cout<<"! ";
    for(int i = 1; i <= n; i++) cout<<v[i]<<" "; cout<<endl;
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