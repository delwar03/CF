#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<vector<int>> v;
    priority_queue<vector<int>> pq;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        if(x) pq.push({x, i + 1});
    }
    vector<vector<int>> ans;
    while(pq.size() > 1) {
        int x1 = pq.top()[0];
        int ind1 = pq.top()[1];
        pq.pop();
        int x2 = pq.top()[0];
        int ind2 = pq.top()[1];
        pq.pop();
        ans.push_back({ind1, ind2});
        if(x1 > 1) pq.push({x1 - 1, ind1});
        if(x2 > 1) pq.push({x2 - 1, ind2});
    }
    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it[0]<<" "<<it[1]<<endl;
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