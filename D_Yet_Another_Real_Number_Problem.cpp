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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) ret = (ret * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ret;
    };

    int cnt = 0, sm = 0;

    auto getCnt = [&] (int x) {
        int ct = 0, tmp = x;
        while(tmp % 2 == 0) {
            tmp /= 2;
            ct++;
        }
        return make_pair(ct, tmp);
    };

    vector<int> dp(n);

    for(int i = 0; i < n; i++) {
        cerr<<i<<": "<<sm<<", "<<cnt<<endl;
        if(i) {
            dp[i] = dp[i - 1] + v[i];
            auto [ct, tmp] = getCnt(v[i]);
            dp[i] = max(dp[i], (sm + (binPow(2, cnt) * v[i]) % mod) % mod);
            cnt += ct;
            sm += tmp;
        } else {
            dp[i] = v[i];
            auto [ct, tmp] = getCnt(v[i]);
            cnt += ct;
            sm += tmp;
        }
    }

    for(int i = 0; i < n; i++) cout<<dp[i]<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x = (((__int128) 8 * 502211460 + 65974071) % mod);
    cerr<<x<<endl;

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