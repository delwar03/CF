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
const int MX = (1LL << 30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> g[n];
    vector<vector<int>> cc;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        if(t == 1) {
            int i, x; cin >> i >> x;
            cc.push_back({--i, x});
        } else {
            int i, j, x; cin >> i >> j >> x;
            cc.push_back({--i, --j, x});
            g[i].push_back({j, x});
            g[j].push_back({i, x});
        }
    }

    auto get = [&] (int l, int r) {
        return l + rng() % (r - l + 1);;
    };

    vector<int> ans(n, -1);
    int bad = 0;

    function<void(int)> dfs = [&] (int u) {
        if(bad) return;
        for(auto [v, x] : g[u]) {
            if(ans[v] == -1) {
                ans[v] = ans[u] ^ x;
                dfs(v);
            } else if((ans[u] ^ ans[v]) != x) {
                bad = 1;
                return;
            }
        }
    };

    auto chk = [&] () {
        for(auto it : cc) {
            if(sz(it) == 2) {
                if(ans[it[0]] == it[1]) return false;
            } else {
                if((ans[it[0]] ^ ans[it[1]]) != it[2]) return false;
            }
        }
        return true;
    };

    do {
        ans = vector<int>(n, -1);
        for(int i = 0; i < n; i++) if(ans[i] == -1) {
            ans[i] = get(0, MX);
            dfs(i);
        }
        if(bad) {cout << "NO" << endl; return; }
    } while(!chk());

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}