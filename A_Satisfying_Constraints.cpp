#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    int mn = -1, mx = INF;
    set<int> forbidden;
    for(int i = 0; i < n; i++) {
        int type, val; cin>>type>>val;
        if(type == 1) mn = max(mn, val);
        else if(type == 2) mx = min(mx, val);
        else forbidden.insert(val);
    }
    int cnt = 0;
    for(auto it : forbidden) {
        if(it >= mn && it <= mx)  cnt++;
    }
    // for(auto it : forbidden) cout<<it<<" "; cout<<endl;
    int ans = max(0LL, mx - mn - cnt + 1);

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