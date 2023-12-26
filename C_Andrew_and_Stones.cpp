#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    if(n == 3 && (v[1] & 1)) {cout<<"-1\n"; return; }
    bool hobe = true;
    for(int i = 1; i < n - 1; i++) {
        if(v[i] != 1) {hobe = false; break;}
    }
    if(hobe) {cout<<"-1\n"; return; }
    int ans = 0;
    for(int i = 1; i < n - 1; i++)
        ans += (v[i] + 1) / 2;
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