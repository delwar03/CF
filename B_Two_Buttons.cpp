#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    map<int, int> dis;
    queue<int> q;
    q.push(n);
    dis[n] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == m) {cout<<dis[u]<<endl; return;}
        if(u * 2 <= 10000 && dis[2 * u] == 0) {
            q.push(2 * u);
            dis[2 * u] = dis[u] + 1;
        }
        if(u > 1 && dis[u - 1] == 0) {
            q.push(u - 1);
            dis[u - 1] = dis[u] + 1;
        }
    }
    cout<<"-1\n";
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