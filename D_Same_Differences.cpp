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
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        v[i] -= i + 1;
    }
    // for(auto it : v) cout<<it<<" "; cout<<endl;
    sort(v.begin(), v.end());
    int ans = 0, cnt = 1;
    for(int i = 0; i < n - 1; i++) {
        if(v[i] == v[i + 1]) cnt++;
        else { ans += cnt * (cnt - 1) / 2; cnt = 1; }
    }
    // for(auto it : v) cout<<it<<" "; cout<<endl;
    if(cnt != 1) ans += cnt * (cnt - 1) / 2;
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