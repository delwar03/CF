#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
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

#define matrix vector<vector<int>>

void solve() {
    int n, m, q; cin>>n>>m>>q;
    matrix adj(n, vector<int>(n));
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        --u; --v;
        adj[u][v] = 1;
    }

    auto matMult = [&] (const matrix& a,const  matrix& b) {
        int x = sz(a), y = sz(b), z = sz(b[0]);
        matrix ret(x, vector<int>(z, 0));
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < z; j++) {
                for(int k = 0; k < y; k++) {
                    (ret[i][j] += (1LL * a[i][k] * b[k][j]) % mod) %= mod;
                }
            }
        }
        return ret;
    };

    vector<matrix> pwr{adj};
    for(int i = 0; i <= 30; i++) pwr.push_back(matMult(pwr.back(), pwr.back()));

    while(q--) {
        int u, v, k; cin>>u>>v>>k;
        --u; --v;
        matrix tmp(n, vector<int>(1));
        tmp[v][0] = 1;
        for(int i = 30; i >= 0; i--) if(k >> i & 1) tmp = matMult(pwr[i], tmp);
        cout<<tmp[u][0]<<endl;
    }
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