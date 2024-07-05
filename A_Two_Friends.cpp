#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;
vector<int> v, vis;

int dfs(int i) {
    vis[i] = 1;
    int tot = 1;
    if(!vis[v[i]]) {
        tot += dfs(v[i]);
    }
    return tot;
}

void solve() {
    int n; cin>>n;
    v.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) cin>>v[i];
    
    int ans = INF;
    for(int i = 1; i <= n; i++) {
        vis.assign(n + 1, 0);
        if(!vis[i]) {
            ans = min(ans, dfs(i));
        }
    }
    cout<<min(3LL, ans)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/