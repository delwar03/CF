#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int x, y, z, k; cin>>x>>y>>z>>k;
    int ans = 0;

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y; j++) {
            if(k % (i * j) == 0) {
                int a = i, b = j, c = k / (i * j);
                if(c <= z) {
                    ans = max(ans, (x - a + 1) * (y - b + 1) * (z - c + 1));
                }
            }
        }
    }
    cout<<ans<<endl;
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