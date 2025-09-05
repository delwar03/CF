#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
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

// cow game problem

void solve() {
    int n, m; cin>>n>>m;
    vector<int> L(m), R(m), S(m);
    for(int i = 0; i < m; i++) cin>>L[i]>>R[i]>>S[i];

    vector<array<int, 3>> edges;
    for(int i = 1; i <= n; i++) edges.push_back({i, i - 1, -1});
    for(int i = 0; i < m; i++) {
        edges.push_back({L[i] - 1, R[i], +S[i]});
        edges.push_back({R[i], L[i] - 1, -S[i]});
    }

    vector<int> dist(n + 1, INF);
    dist[n] = 0;
    int f = 1;
    for(int i = 0; i <= n; i++) {
        f = 0;
        for(auto [u, v, d] : edges) {
            if(dist[u] != INF && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                f = 1;
            }
        }
        if(!f) break;
    }
    cout<<(f ? -1 : -dist[0])<<endl;
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