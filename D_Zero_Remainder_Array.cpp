#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    map<int, int> mp;
    
    for(auto &x : v) {
        cin>>x;
        x = (k - x % k) % k;
    }
    // sort(v.begin(), v.end());
    for(auto it : v) {
        if(it) mp[it]++;
    }
    // for(auto it : mp) cerr<<it.first<<" "<<it.second<<endl; cerr<<endl;
    int ans = 0;
    for(auto &it : mp) {
        int p = (it.second - 1) * k + it.first;
        ans = max(ans, p);
    }
    if(ans) ans++;
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 