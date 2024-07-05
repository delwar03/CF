#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    vector<int> b(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        b[i] = mx;
    }
    int ans = 0;
    mx = 0;
    for(int i = 0; i < n; i++) {
        ans += b[i] - a[i];
        mx = max(mx, b[i] - a[i]);
    }
    cout<<ans + mx<<endl;
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