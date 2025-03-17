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

void solve() {
    int n, q; cin>>n>>q;
    vector<int> E(n), S(n);
    vector<vector<int>> dist(n, vector<int>(n));
    while(q--) {
        int i; char op; cin>>i>>op;
        --i;
        if(op == '+') {
            E[i] += 1;
        }  else {
            S[i] += 1;
        }

        for(int j = 0; j < n; j++) if(i ^ j) dist[i][j] = max(dist[i][j], E[i] - S[j] + 1);
        for(int j = 0; j < n; j++) if(i ^ j) dist[j][i] = max(dist[j][i], E[j] - S[i] + 1);
    }

    vector<vector<int>> dp(n, vector<int>((1LL << n), -1));

    function<int(int, int)> magic = [&] (int i, int mask) {
        if(__builtin_popcount(mask) == n) return E[i];
        int &ans = dp[i][mask];
        if(~ans) return ans;

        ans = INF;
        for(int j = 0; j < n; j++) if(!(mask >> j & 1)) {
            ans = min(ans, dist[i][j] + magic(j, mask | (1LL << j)));
        }

        return ans;
    };

    int ans = INF;
    for(int i = 0; i < n; i++) {
        ans = min(ans, 1 + magic(i, 1LL << i));
    }

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