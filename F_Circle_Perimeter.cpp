#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int r; cin>>r;
    int ans = 0, h = r;
    for(int i = 0; i <= r; i++) {
        while(i * i + h * h >= (r + 1) * (r + 1)) {
            h--;
        }
        int p = h;
        while(p > 0 && i * i + p * p >= r * r) {
            p--;
            ans++;
        }
    }
    cout<<4 * ans<<endl;
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