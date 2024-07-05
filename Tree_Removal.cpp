#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

vector<int> g[N];
vector<int> ord;

void dfs(int u, int p = 0) {
    for(auto v : g[u]) {
        if(v ^ p) {
            dfs(v, u);
        }
    }
    ord.push_back(u);
}


void reset(int n) {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
    ord.clear();
}

void solve() {
    int n; cin>>n;
    reset(n);
    vector<int> v(n + 1);
    int mn = INF, root;
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        if(v[i] < mn) {
            mn = v[i];
            root = i;
        }
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(root);
    ord.pop_back();
    cout<<(int) ord.size()<<endl;
    for(auto it : ord) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/