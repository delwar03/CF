#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int ans = 0;
    for(int i = n - 1; i > 0; i--) {
        ans += abs(v[i] - v[i - 1]);
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int val = 0;
        if(i > 0) val += abs(v[i] - v[i - 1]);
        if(i < n - 1) val += abs(v[i] - v[i + 1]);
        if(i > 0 && i < n - 1) val -= abs(v[i + 1] - v[i - 1]);

        mx = max(mx, val);
    }
    cout<<ans - mx<<endl;
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