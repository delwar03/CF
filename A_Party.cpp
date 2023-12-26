#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> g[n + 1];
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        if(x == -1) q.push({i, 0});
        else g[x].push_back(i);
    }
    int mx = 0;
    while(!q.empty()) {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();
        mx = max(mx, d);
        for(auto v : g[u]) {
            q.push({v, d + 1});
        }
    }
    cout<<mx + 1<<endl;
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