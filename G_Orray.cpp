#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n), vis(n);
    for(auto &x : v) cin>>x;

    int orr = 0;
    for(int i = 0; i < min(32LL, n); i++) {
        int mx = 0, ind = -1;
        for(int j = 0; j < n; j++) {
            if(!vis[j]) {
                if((orr | v[j]) > mx) {
                    mx = (orr | v[j]);
                    ind = j;
                }
            }
        }
        cout<<v[ind]<<" ";
        orr |= v[ind];
        vis[ind] ^= 1;
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cout<<v[i]<<" ";
        }
    }
    cout<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/