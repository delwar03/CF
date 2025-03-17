#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[31][N];

void solve() {
    int n, k; cin>>n>>k;
    vector<int> g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> par(n + 1), dep(n + 1);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for(auto v : g[u]) {
            if(v ^ p) {
                dep[v] = 1 + dep[u];
                par[v] = u;
                dfs(v, u);
            }
        }
    };

    dfs(1, 0);

    for(int i = 0; i < 31; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    vector<int> v(k);
    for(auto &x : v) cin>>x;

    vector<int> vis(n + 1);
    vis[0] = 1;
    set<int> st;

    auto LCA = [&] (int u, int v) {
        if(dep[u] > dep[v]) swap(u, v);
        int k = dep[v] - dep[u];
        for(int i = 30; i >= 0; i--) {
            if(k & (1LL << i)) {
                v = dp[i][v];
            }
        }
        if(u == v) return u;

        for(int i = 30; i >= 0; i--) {
            if(dp[i][u] != dp[i][v]) {
                u = dp[i][u];
                v = dp[i][v];
            }
        }

        u = dp[0][u];
        v = dp[0][v];

        assert(u == v);

        return u;
    };
    
    int lca = v[0];
    st.insert(v[0]);
    vis[v[0]] = 1;

    for(int i = 1; i < k; i++) {
        int cur = LCA(lca, v[i]);
        int tmp = par[lca];

        while(!vis[tmp] && tmp != par[cur]) {
            st.insert(tmp);
            vis[tmp] = 1;
            tmp = par[tmp];
        }
        
        tmp = v[i];
        while(!vis[tmp] && tmp != par[cur]) {
            st.insert(tmp);
            vis[tmp] = 1;
            tmp = par[tmp];
        }

        lca = cur;
    }

    cout<<(int) st.size()<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/