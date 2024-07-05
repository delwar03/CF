#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int d, c; cin>>d>>c;
        if(mp.count(c)) {
            if(d < mp[c]) mp[c] = d;
        } else {
            mp[c] = d;
        }
    }
    int ans = 0;
    for(auto it : mp) {
        ans = max(ans, it.second);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
