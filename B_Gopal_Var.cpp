#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> g[N];
vector<int> dist(N, INF);

void dijkstra(int src) {
    set<vector<int>> st;
    dist[src] = 0;
    st.insert({0, src});

    while(st.size()) {
        int node = (*st.begin())[1];
        int wt = (*st.begin())[0];
        st.erase(st.begin());

        for(auto it : g[node]) {
            int child = it[0];
            int dst = it[1];
            if(wt + dst < dist[child]) {
                dist[child] = wt + dst;
                st.insert({dist[child], child});
            }
        }
    }
}

void solve() {
    int n; cin>>n;
    for(int i = 0; i < n - 1; i++) {
        int a, b, x; cin>>a>>b>>x;
        x--;
        g[i].push_back({i + 1, a});
        g[i].push_back({x, b});
    }
    dijkstra(0);
    cout<<dist[n - 1]<<endl;
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