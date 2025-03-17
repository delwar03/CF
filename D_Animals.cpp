#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

int dp[105][10005]; // (ind, rem)

void solve() {
    int n, x; cin>>n>>x;
    vector<int> cost(n);
    for(auto &x : cost) cin>>x;

    function<int(int, int)> magic = [&] (int ind, int rem) {
        if(ind == n) return 0LL;

        int &ans = dp[ind][rem];
        if(~ans) return ans;

        ans = 0;
        ans = max(ans, magic(ind + 1, rem));
        if(rem - (n - ind) * cost[ind] >= 0)
            ans = max(ans, 1 + magic(ind + 1, rem - (n - ind) * cost[ind]));

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, x)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

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
