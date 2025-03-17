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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[63][2];
int ndp[63][2];

void solve() {
    int n, m; cin>>n>>m;
    bitset<62> a(n), b(m);

    function<int(int, int)> func = [&] (int ind, int tight) {
        if(ind == 62) {
            return (int) 1LL;
        }
        int &ans = ndp[ind][tight];
        if(~ans) return ans;
        ans = 0;
        int mx = tight ? a[ind] : 1;
        for(int i = 0; i <= mx; i++) {
            ans += func(ind + 1, tight & (i == mx));
            ans %= mod;
        }
        return ans;
    };

    function<int(int, int)> magic = [&] (int ind, int tight) {
        if(ind == 62) {
            return (int) 0LL;
        }
        int &ans = dp[ind][tight];
        if(~ans) return ans;
        ans = 0;
        int mx = tight ? a[ind] : 1;
        
        for(int i = 0; i <= mx; i++) {
            if(b[ind] && i) {
                int cnt = func(ind + 1, tight & (i == mx));
                ans += cnt;
                ans %= mod;
            }
            ans += magic(ind + 1, tight & (i == mx));
            ans %= mod;
        }
        return ans;
    };


    auto tmp = a;
    for(int i = 0; i < 62; i++) {
        tmp[i] = a[62 - 1 - i];
    }
    a = tmp;
    tmp = b;
    for(int i = 0; i < 62; i++) {
        tmp[i] = b[62 - 1 - i];
    }
    b = tmp;

    // for(int i = 0; i < 62; i++) cout<<a[i]<<' '; cout<<endl;
    // for(int i = 0; i < 62; i++) cout<<b[i]<<' '; cout<<endl;

    memset(dp, -1, sizeof dp);
    memset(ndp, -1, sizeof ndp);
    cout<<magic(0, 1)<<endl;
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

/*
i/p: 
o/p: 
*/