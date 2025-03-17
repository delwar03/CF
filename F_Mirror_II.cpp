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
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int siz = 1;
    map<int, int> cnt;
};

void solve() {
    int n; cin>>n;
    vector<int> val(n + 1), g[n + 1], par(n + 1);
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 2; i <= n; i++) {
        cin>>par[i];
        g[i].push_back(par[i]);
        g[par[i]].push_back(i);
    }

    int ans = 0;
    vector<map<int, int>> ds(n + 1);

    function<void(int, int, int)> dfs = [&] (int u, int p, int d) {
        d += val[u];
        ds[u][d] += 1;
        int x1 = INF, x2 = INF, D = 1 - 8 * d + 4 * val[u];

        if(D > 0 && (D % 2 == 1)) {
            int rt = sqrtl(D);
            if(rt * rt == D) {
                x1 = (1 + rt) / 2;
                x2 = (1 - rt) / 2;
            }
        }

        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u, d);
                if(sz(ds[u]) > sz(ds[v])) swap(ds[u], ds[v]);

                for(auto [a, b] : ds[v]) {
                    if(a == x1 || a == x2) {
                        ans += b * ds[u][0];
                    } else if(a == 0) {
                        // if(x1 == INF) continue;
                        ans += b * ds[u][x1];
                        ans += b * ds[u][x2];
                    }
                }

                for(auto [a, b] : ds[v]) {
                    if(b)
                        ds[u][a] += b;
                }
            }
        }
    };

    dfs(1, 0, 0);
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