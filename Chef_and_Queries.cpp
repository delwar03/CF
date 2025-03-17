#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
// const int mod = 1e9 + 7;
const int N = 3e9 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bitset<N> bst;

void solve() {
    int q, s, a, b; cin>>q>>s>>a>>b;
    int ans = 0, mod = (1LL << 32);
    for(int i = 0; i < q; i++) {
        if(i) s = ((a * s) % mod + b) % mod;
        if(s & 1) {
            int cur = s / 2;
            if(!bst[cur]) {
                bst[cur] = 1;
                ans += cur;
            }
        } else {
            int cur = s / 2;
            if(bst[cur]) {
                bst[cur] = 0;
                ans -= cur;
            }
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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