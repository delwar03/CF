#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, sum = 0; cin>>n;
    vector<int> v(n);
    for(auto &x : v) {cin>>x; sum += x;}
    int ans = 0, id = 1;
    for(int i = 0; i < n; i++) {
        if(sum - v[i] > 0) ans += (id++) * v[i];
        else ans += (id) * v[i];
        sum -= v[i];
    }
    cout<<ans<<endl;
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