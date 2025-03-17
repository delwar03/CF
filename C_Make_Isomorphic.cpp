#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    int mg; cin>>mg;
    vector<vector<int>> G(n, vector<int>(n)), H(n, vector<int>(n));
    for(int i = 0; i < mg; i++) {
        int u, v; cin>>u>>v;
        --u; --v;
        G[u][v] = G[v][u] = 1;
    }
    int mh; cin>>mh;
    for(int i = 0; i < mh; i++) {
        int u, v; cin>>u>>v;
        --u; --v;
        H[u][v] = H[v][u] = 1;
    }
    vector<vector<int>> cost(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cin>>cost[i][j];
        }
    }

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0LL);

    int ans = INF;

    do {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(H[i][j] != G[perm[i]][perm[j]]) cur += cost[i][j];
            }
        }
        ans = min(ans, cur);
    } while(next_permutation(perm.begin(), perm.end()));

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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