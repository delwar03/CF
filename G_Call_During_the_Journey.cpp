#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    int t0, t1, t2; cin>>t0>>t1>>t2;
    vector<vector<int>> g[n + 1];

    for(int i = 0; i < m; i++) {
        int u, v, w1, w2; cin>>u>>v>>w1>>w2;
        g[u].push_back({v, w1, w2});
        g[v].push_back({u, w1, w2});
    }

    // st.....en

    auto canTakeBus = [&] (int st, int en) {
        return (t2 <= st || t1 >= en);
    };

    auto dijkstra = [&] (int start_time) {
        vector<int> dist(n + 1, INF);
        // set e vector nile beshi time ney
        // pair niye AC :)
        set<pair<int, int>> st; // {wt, node}
        st.insert({start_time, 1});
        dist[1] = start_time;

        while(st.size()) {
            auto node = *(st.begin());
            st.erase(st.begin());
            int u = node.ss, wt = node.ff;

            for(auto it : g[u]) {
                int v = it[0], w1 = it[1], w2 = it[2];

                int mn = INF;

                if(wt + w2 < mn) mn = wt + w2;

                if(canTakeBus(wt, wt + w1)) {
                    if(wt + w1 < mn) mn = wt + w1;
                } else {
                    if(t2 + w1 < mn) mn = t2 + w1;
                }

                if(mn < dist[v]) {
                    if(dist[v] != INF) st.erase({dist[v], v});
                    dist[v] = mn;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist[n];
    };

    int l = 0, r = t0, best = -1;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(dijkstra(mid) <= t0) {
            best = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout<<best<<endl;
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