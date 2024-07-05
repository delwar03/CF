#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) {cin>>x; }
    bool f = true;
    // while(v.size() > 2) {
    //     if(v[1] >= 2 * v[0] && v[2] >= v[0]) {
    //         v[1] -= 2 * v[0];
    //         v[2] -= v[0];
    //     } else {
    //         f = false;
    //         break;
    //     }
    //     v.erase(v.begin());
    // }
    for(int i = 0; i < n - 2; i++) {
        if(v[i + 1] >= 2 * v[i] && v[i + 2] >= v[i]) {
            v[i + 1] -= 2 * v[i];
            v[i + 2] -= v[i];
        } else {
            f = false;
            break;
        }
    }
    if(v[n - 1] != 0 || v[n - 2] != 0) f = false;
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 