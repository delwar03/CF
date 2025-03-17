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
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    vector<int> cost;
    vector<vector<int>> v(m);
    for(int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        cost.push_back(a);
        for(int j = 0; j < b; j++) {
            int c; cin>>c;
            --c;
            v[i].push_back(c);
        }
    }

    // for(auto it : cost) cerr<<it<<" "; cerr<<endl;

    // for(int i = 0; i < m; i++) {
    //     for(int j : v[i]) cerr<<j<<" "; cerr<<endl;
    // }

    vector<vector<int>> dp(m, vector<int>(1LL << n, -1));

    function<int(int, int)> magic = [&] (int ind, int mask) {
        if(ind == m) {
            if(mask == (1LL << n) - 1) return 0LL;
            return INF;
        }

        int &ans = dp[ind][mask];
        if(~ans) return ans;

        ans = INF;
        ans = min(ans, magic(ind + 1, mask));
        int nMask = mask;
        for(auto j : v[ind]) nMask |= (1LL << j);
        ans = min(ans, cost[ind] + magic(ind + 1, nMask));

        return ans;
    };

    int ans = magic(0, 0);

    cout<<(ans == INF ? -1 : ans)<<endl;
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