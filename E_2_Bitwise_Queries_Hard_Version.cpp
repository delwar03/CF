#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1), ind(n + 1, -1);

    for(int i = 2; i <= n; i++) {
        cout<<"XOR "<<1<<" "<<i<<endl;
        cin>>v[i];
    }

    int j = -1, k = -1;
    for(int i = 2; i <= n; i++) {
        if(~ind[v[i]]) {
            j = ind[v[i]];
            k = i;
        }
        ind[v[i]] = i;
    }

    if(~j) {
        cout<<"AND "<<j<<" "<<k<<endl;
        int val; cin>>val;
        v[1] = v[j] ^ val;
        for(int i = 2; i <= n; i++) v[i] ^= v[1];
    } else {

        for(int i = 2; i <= n; i++) {
            if(~ind[v[i] ^ (n - 1)]) {
                j = i;
                k = ind[v[i] ^ (n - 1)];
                break;
            }
        }

        int x, y, z;
        int XOR1, AND1, XOR2, AND2, XOR3, AND3;

        XOR1 = v[j];    // v[1] ^ v[j]
        cout<<"AND "<<1<<" "<<j<<endl;
        cin>>AND1;      // v[1] & v[j]
        x = XOR1 + 2 * AND1;

        XOR2 = n - 1;   // v[j] ^ v[k]
        AND2 = 0;       // v[j] & v[k]
        y = XOR2 + 2 * AND2;

        XOR3 = XOR1 ^ XOR2; // v[1] ^ v[k] => (v[1] ^ v[j]) ^ (v[j] ^ v[k])
        cout<<"AND "<<1<<" "<<k<<endl;
        cin>>AND3;          // v[1] & v[k]
        z = XOR3 + 2 * AND3;

        v[1] = (x + z - y) / 2;

        for(int i = 2; i <= n; i++) v[i] ^= v[1];
    }

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