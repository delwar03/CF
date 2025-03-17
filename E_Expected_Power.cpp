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
    int n, m = 1e4; cin>>n;
    vector<int> v(n), p(n);
    for(auto &x : v) cin>>x;
    for(auto &x : p) cin>>x;

    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) {
                ret = (ret * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ret;
    };

    auto inv = [&] (int a) {
        return binPow(a, mod - 2);
    };

    vector<vector<int>> dp(n, vector<int>(1024, -1));

    function<int(int, int)> magic = [&] (int ind, int xorr) {
        if(ind == n) return 1LL;
        int &ans = dp[ind][xorr];
        if(~ans) return ans;
        ans = 1;
        ans = (ans * ((m - p[ind]) * magic(ind + 1, xorr)) % mod) % mod;
        ans = (ans * (p[ind] * magic(ind + 1, xorr ^ v[ind])) % mod) % mod;
        return ans;
    };

    magic(0, 0);

    for(int i = 0; i <= 1023; i++) {
        cerr<<dp[n - 1][i]<<" ";
    }

    int ans = 0;

    for(int x = 0; x <= 1023; x++) {
        if(~dp[n - 1][x])
            ans = (ans + (binPow(x, 2) * dp[n - 1][x]) % mod) % mod;
    }

    ans = (ans * inv(m)) % mod;

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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