#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int a[2], b[2]; cin>>a[0]>>a[1]>>b[0]>>b[1];
    int ans = 0;

    for(int i = 0; i < 4; i++) {
        int f = 0;
        if(a[0] > b[0]) f++;
        if(a[0] < b[0]) f--;

        if(a[1] > b[1]) f++;
        if(a[1] < b[1]) f--;

        if(f > 0) ans++;

        swap(a[0], a[1]);
        if(i == 1) swap(b[0], b[1]);
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