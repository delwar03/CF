#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    vector<int> ans;
    for(int i = 1; i < n; i++) {
        if(__gcd(i, n) == 1) ans.push_back(i);
    }
    int mul = 1;
    for(auto it : ans) mul = (mul * it) % n;
    if(mul == 1) {
        cout<<ans.size()<<endl;
        for(auto it : ans) cout<<it<<" "; cout<<endl;
    } else {
        cout<<ans.size() - 1<<endl;
        for(auto it : ans) if(it != mul) cout<<it<<" "; cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 