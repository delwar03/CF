#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<vector<int>> dist(n, vector<int>(n));
    for(auto &x : dist) for(auto &y : x) cin>>y;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i ^ j) {
            if(!dist[i][j]) dist[i][j] == INF;
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {cout<<-1<<endl; return; }
            }
        }
    }

    vector<array<int, 3>> edges;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            edges.push_back({dist[i][j], i, j});
        }
    }

    sort(edges.begin(), edges.end());
    
    vector<vector<int>> cur(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) cur[i][i] = 0;

    auto print = [&] () {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cerr<<(cur[i][j] == INF ? -1 : cur[i][j])<<" \n"[j == n - 1];
            }
        } cerr<<endl;
    };

    int cost = 0;

    for(auto [w, u, v] : edges) {
        // cerr<<u<<" "<<v<<" "<<w<<endl;

        if(cur[u][v] > dist[u][v]) {
            cost += w;
            cur[u][v] = cur[v][u] = w;

            // print();

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) if(i ^ j) {
                    cur[i][j] = min(cur[i][j], cur[i][u] + w + cur[v][j]);
                    cur[i][j] = min(cur[i][j], cur[i][v] + w + cur[u][j]);
                    cur[j][i] = cur[i][j];
                }
            }
        }

        // print();
    }

    cout<<cost<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}