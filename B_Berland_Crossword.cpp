#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e2 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, u, r, d, l; cin>>n>>u>>r>>d>>l;
    
    auto hobe = [&] (int x) {
        return x >= 0 && x <= n - 2;
    };

    for(int i = 0; i < 16; i++) {
        int ul = (i) & 1;
        int ur = (i >> 1) & 1;
        int dl = (i >> 2) & 1;
        int dr = (i >> 3) & 1;

        if(hobe(u - ur - ul) && hobe(r - ur - dr) && hobe(d - dl - dr) && hobe(l - ul - dl)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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