#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int l1, r1, l2, r2; cin>>l1>>r1>>l2>>r2;
    if(r1 < l2 || r2 < l1) {cout<<1<<endl; return; }
    int mx = max(l1, l2);
    int mn = min(r1, r2);
    int ans = 2;
    if(l1 == l2) ans--;
    if(r1 == r2) ans--;
    // if(mn > mx)
        ans += abs(mn - mx);

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