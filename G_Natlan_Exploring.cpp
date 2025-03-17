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
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int prime[N];
vector<vector<int>> divs(N);

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector<int> dp(n);
    vector<int> sum(N);

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            dp[i] = 1;
        } else {
            int sz = sz(divs[v[i]]), mask = (1LL << sz);
            for(int j = 1; j < mask; j++) {
                int prod = 1, sn = -1;
                for(int k = 0; k < sz; k++) {
                    if((j >> k) & 1) {
                        prod *= divs[v[i]][k];
                        sn *= -1;
                    }
                }
                dp[i] += sn * sum[prod];
                dp[i] = (dp[i] + mod) % mod;
            }
        }
        int sz = sz(divs[v[i]]), mask = (1LL << sz);
        for(int j = 1; j < mask; j++) {
            int prod = 1;
            for(int k = 0; k < sz; k++) {
                if((j >> k) & 1) {
                    prod *= divs[v[i]][k];
                }
            }
            sum[prod] = (sum[prod] + dp[i] + mod) % mod;
        }
    }

    cout<<dp[n - 1]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        if(!prime[i]) {
            for(int j = i; j < N; j += i) {
                if(!prime[j])
                    prime[j] = i;
                divs[j].push_back(i);
            }
        }
    }

    // for(int i = 2; i <= 100; i++) cerr<<i<<" -> "<<prime[i]<<endl;
    // for(int i = 2; i <= 100; i++) {
    //     cerr<<i<<" -> ";
    //     for(auto j : divs[i]) cerr<<j<<" "; cerr<<endl;
    // }

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}