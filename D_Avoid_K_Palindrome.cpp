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

int dp[1005][1024];

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;

    auto isPalin = [&] (int mask) {
        int l = 0, r = k - 1;
        while (l < r) {
            if((mask >> l & 1) != (mask >> r & 1)) return 0LL;
            l++;
            r--;
        }
        return 1LL;
    };

    function<int(int, int)> magic = [&] (int ind, int mask) {
        if(ind == n) return 1 - isPalin(mask);
        int &ans = dp[ind][mask];
        if(~ans) return ans;
        ans = 0;
        if(s[ind] == '?') {
            if(ind >= k) {
                if(!isPalin(mask)) {
                    int newMask = mask << 1LL;
                    newMask &= (1LL << k) - 1;
                    ans = (ans + magic(ind + 1, newMask)) % mod;
                    ans = (ans + magic(ind + 1, (newMask | 1))) % mod;
                }
            } else {
                int newMask = mask << 1LL;
                ans = (ans + magic(ind + 1, (newMask))) % mod;
                ans = (ans + magic(ind + 1, (newMask | 1))) % mod;
            }
        } else {
            if(ind >= k) {
                if(!isPalin(mask)) {
                    int newMask = mask << 1LL;
                    newMask &= (1LL << k) - 1;
                    ans = (ans + magic(ind + 1, (newMask | (s[ind] == 'A' ? 0 : 1)))) % mod;
                }
            } else {
                int newMask = mask << 1LL;
                ans = (ans + magic(ind + 1, (newMask | (s[ind] == 'A' ? 0 : 1)))) % mod;
            }
        }
        return ans;
    };
    
    memset(dp, -1, sizeof dp);
    cout<<magic(0, 0)<<endl;
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