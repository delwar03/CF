#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1, 0), pos(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        pos[x] = i;
        v[i] = x;
    }
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++) {
        
        if(pos[i] != i) {
            ans.push_back({i, pos[i]});
            pos[v[i]] = pos[i];
            v[pos[i]] = v[i];
            pos[i] = i;
            v[i] = i;
        }
    }
    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it[0]<<" "<<it[1]<<endl;
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
