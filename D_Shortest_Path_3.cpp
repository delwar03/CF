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

void solve() {
    int n, m; cin>>n>>m;
    vector<int> val(n + 1);
    for(int i = 1; i <= n; i++) cin>>val[i];
    vector<pair<int, int>> g[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    vector<int> dist(n + 1, INF);
    set<pair<int, int>> st;
    dist[1] = val[1];
    st.insert({dist[1], 1});

    while(st.size()) {
        auto node = *(st.begin());
        st.erase(st.begin());
        int u = node.ss, d = node.ff;

        for(auto it : g[u]) {
            int v = it.ff, wt = it.ss;
            if(dist[u] + wt + val[v] < dist[v]) {
                if(dist[v] != INF) {
                    st.erase({dist[v], v});
                }
                dist[v] = dist[u] + wt + val[v];
                st.insert({dist[v], v});
            }
        }
    }

    for(int i = 2; i <= n; i++) cout<<dist[i]<<" ";
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