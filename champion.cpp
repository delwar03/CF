#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e4 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(int i = 0; i < k; i++) ans += v[i];
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
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 