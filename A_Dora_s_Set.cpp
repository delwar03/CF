#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int l, r; cin>>l>>r;
    // for(int i = l; i <= r; i++) {
    //     cerr<<i<<" ";
    // } cerr<<endl;

    int ans = 0;
    for(int i = l; i <= r; i++) {
        if(i % 2 == 0) continue;
        if(i + 2 > r) break;
        ans++;
        i += 2;
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