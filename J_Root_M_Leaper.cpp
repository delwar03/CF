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

void solve() {
    int n, m; cin>>n>>m;
    int rt = sqrtl(m) + 5;
    vector<pii> tmp;
    for(int i = -rt; i <= rt; i++) {
        for(int j = -rt; j <= rt; j++) {
            if(i * i + j * j == m) tmp.push_back({i, j});
        }
    }

    // for(auto [a, b] : tmp) cerr<<a<<" "<<b<<endl;

    auto id = [&] (int i, int j) {
        return n * i + j;
    };

    auto valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    };

    int sz = n * n + 10;
    vector<pii> g[sz];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(auto [dx, dy] : tmp) {
                int ni = i + dx, nj = j + dy;
                if(valid(ni, nj)) {
                    int u = id(i, j), v = id(ni, nj);
                    g[u].push_back({v, 1});
                    g[v].push_back({u, 1});
                }
            }
        }
    }


    vector<int> dp(n * n + 1, INF);
    dp[0] = 0;
    queue<pii> q;
    q.push({0, 0});

    while(sz(q)) {
        auto [d, u] = q.front(); q.pop();
        for(auto [v, wt] : g[u]) {
            if(d + wt < dp[v]) {
                dp[v] = d + wt;
                q.push({dp[v], v});
            }
        }
    }


    for(int i = 0; i < n * n; i++) {
        cout<<(dp[i] == INF ? -1 : dp[i])<<" \n"[i % n == n - 1];
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