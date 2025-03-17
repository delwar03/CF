#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

#define f first
#define s second

pair<int, int> dp[N]; // {max_pos, max_neg}


void solve() {
    int n; cin>>n;
    vector<int> g[n + 1], val(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) cin>>val[i];

    if(n == 1) {
        cout<<(val[1] + mod) % mod<<endl;
        return;
    }

    auto binPow = [&] (int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    };

    auto upd = [&] (int x, pair<int, int> pr) {
        if(x == 1) {
            return make_pair(pr.f, pr.s);
        } else if(x == -1) {
            return make_pair(pr.s, pr.f);
        } else if(x == 2) {
            return make_pair(pr.f + 1, pr.s + 1);
        } else if(x == -2) {
            return make_pair(pr.s + 1, pr.f + 1);
        } else {
            //
        }
    };

    int cnt = 0;

    function<void(int, int)> dfs = [&] (int u, int p) {

        dp[u] = {0, -INF};
        vector<pair<int, int>> pos, neg;

        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u);
                pos.push_back({dp[v].f, v});
                neg.push_back({dp[v].s, v});
            }
        }

        sort(pos.rbegin(), pos.rend());
        sort(neg.rbegin(), neg.rend());

        if(pos.size()) {
            dp[u].f = max(dp[u].f, pos[0].f);
            dp[u].s = max(dp[u].s, neg[0].f);

            if(pos.size() > 1) {
                pair<int, int> tmp = {0, -INF};
                if(pos[0].s == neg[0].s) {
                    tmp.s = max(pos[0].f + neg[1].f, pos[1].f + neg[0].f);
                } else {
                    tmp.s = pos[0].f + neg[0].f;
                }
                tmp.f = max(pos[0].f + pos[1].f, neg[0].f + neg[1].f);
                tmp = upd(val[u], tmp);
                cnt = max(cnt, tmp.f);
            }
        }
        dp[u] = upd(val[u], dp[u]);
        cnt = max(cnt, dp[u].f);
    };

    dfs(1, 0);

    int ans = binPow(2, cnt);
    cout<<ans<<endl;
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
