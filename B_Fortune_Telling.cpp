#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, x, y; cin>>n>>x>>y;
    vector<int> v(n);
    for(auto &a : v) cin>>a;
    int a = x & 1;
    for(auto it : v) {
        a ^= (it & 1);
    }
    if((y & 1) == a) cout<<"Alice\n";
    else cout<<"Bob\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 
o/p: 
*/ 