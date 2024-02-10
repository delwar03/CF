#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;


void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> f(n + 1), b(n + 1);
    for(int i = 0; i < n - 1; i++) {
        if(i == 0 || abs(v[i + 1] - v[i]) < abs(v[i] - v[i - 1])) f[i + 1] = 1;
        else f[i + 1] = abs(v[i + 1] - v[i]);
    }
    for(int i = n - 1; i > 0; i--) {
        if(i == n - 1 || abs(v[i] - v[i - 1]) < abs(v[i] - v[i + 1])) b[i] = 1;
        else b[i] = abs(v[i] - v[i - 1]);
    }
    for(int i = 1; i <= n; i++) f[i] += f[i - 1];
    for(int i = n; i > 0; i--) b[i - 1] += b[i];
    // for(auto it : f) cout<<it<<" "; cout<<endl;
    // for(auto it : b) cout<<it<<" "; cout<<endl;
    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        if(l < r) cout<<f[r - 1] - f[l - 1]<<endl;
        else cout<<b[r] - b[l]<<endl;
    }
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