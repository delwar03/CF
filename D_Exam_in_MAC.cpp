#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, c; cin>>n>>c;
    int even = 0, odd = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        if(x & 1) odd++;
        else even++;
    }
    int ans = (c + 1) * (c + 2) / 2;
    for(int i = 0; i < n; i++) {
        ans -= (v[i] / 2 + 1);
        ans -= (c - v[i] + 1);
    }
    ans += even * (even + 1) / 2;
    ans += odd * (odd + 1) / 2;
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