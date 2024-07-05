#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<int> b(n), c(m);
    int ans = 0;
    for(auto &x : b) {cin>>x; }
    for(auto &x : c) {cin>>x; }
    for(auto &x : b) {
        for(auto &y : c) {
            ans += (x + y <= k);
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
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 