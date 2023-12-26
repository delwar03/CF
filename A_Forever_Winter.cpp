#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;


void solve() {
    int n, m; cin>>n>>m;
    vector<int> g[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map<int, int> mp;
    // for(int i = 1; i <= n; i++) {
    //     for(auto it : g[i]) cerr<<it<<" ";
    //     cerr<<endl;
    // }
    for(int i = 1; i <= n; i++) {
        if(g[i].size() > 1) mp[g[i].size()]++;
    }
    // for(auto it : mp) cerr<<it.first<<" "<<it.second<<endl;
    if(mp.size() == 1) cout<<(*mp.begin()).first<<" "<<(*mp.begin()).first - 1<<endl;
    else {
        int x, y;
        for(auto it : mp) {
            if(it.second == 1) x = it.first;
            else y = it.first - 1;
        }
        cout<<x<<" "<<y<<endl;
    }
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