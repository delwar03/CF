#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<int>> ans;
    ans.push_back({1, 1});
    ans.push_back({1, 2});

    for(int i = 3; i < n; i++) {
        ans.push_back({i, 1});
    }

    if(ans.size() != n) ans.push_back({n, n});

    for(auto v : ans) cout<<v[0]<<" "<<v[1]<<endl; cout<<endl;
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
