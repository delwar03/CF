#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<int>> v;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        sum += x;
        v.push_back({x, y});
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, sum - v[i][0] + v[i][1]);
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
