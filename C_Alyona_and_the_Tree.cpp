#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

int dp[15][256][2]; // (ind, mask, tight)

string getNum(int n) {
    string res = "";
    while(n) {
        res.push_back((char) (n % 7 + '0'));
        n /= 7;
    }
    if(!res.size()) res += "0";
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int n; cin>>n;
    vector<int> val(n + 1);
    vector<vector<int>> g[n + 1];
    for(int i = 1; i <= n; i++) cin>>val[i];

    for(int i = 2; i <= n; i++) {
        int p, wt; cin>>p>>wt;
        g[p].push_back({i, wt});
        g[i].push_back({p, wt});
    }

    vector<int> dp(n + 1, 0);

    int ans = 0;

    function<void(int, int, int)> dfs = [&] (int u, int p, int f) {
        dp[u] = max(0LL, dp[u]);
        if(dp[u] > val[u]) f = 1;
        ans += f;
        
        for(auto it : g[u]) {
            int v = it[0], wt = it[1];
            if(v ^ p) {
                dp[v] = dp[u] + wt;
                dfs(v, u, f);
            }
        }
    };

    dfs(1, 0, 0);

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
