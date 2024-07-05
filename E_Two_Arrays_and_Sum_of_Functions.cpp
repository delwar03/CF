#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    sort(b.begin(), b.end());

    vector<int> temp(n);
    
    for(int i = 0; i < n; i++) {
        temp[i] = a[i] * (i + 1) * (n - i);
    }

    sort(temp.rbegin(), temp.rend());
    
    // for(auto it : temp) cerr<<it<<" "; cerr<<endl;

    for(int i = 0; i < n; i++) {
        temp[i] = ((temp[i] % mod) * b[i]) % mod;
    }

    int ans = 0;
    for(auto it : temp) ans = (ans + it) % mod;

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/