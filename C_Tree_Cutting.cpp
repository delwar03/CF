#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
vector<int> sz(N, 0);
vector<int> g[N];
int n, k, cnt = 0;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void dfs(int node, int par, int mid) {
    sz[node] = 1;
    for(auto child : g[node]) {
        if(child ^ par) {
            dfs(child, node, mid);
            sz[node] += sz[child];
        }
    }
    if(sz[node] >= mid && cnt < k && par != -1) {
        cnt++;
        sz[node] = 0;
    }
}

void solve() {
    cin>>n>>k;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    int l = 1, r = n;
    while(l <= r) {
        for(int i = 0; i <= n; i++) sz[i] = 0;
        int mid = (l + r) >> 1;
        cnt = 0;
        dfs(1, -1, mid);
        if(cnt >= k && sz[1] >= mid) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout<<ans<<endl;
    for(int i = 0; i <= n; i++) {
        g[i].clear();
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