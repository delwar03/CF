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

int dp[62][N];

void solve() {
    int n, k; cin>>n>>k; k = 1;
    vector<int> par(n + 1);
    for(int i = 1; i <= n; i++) cin>>par[i];

    cerr<<"par: ";
    for(int i = 1; i <= n; i++) cerr<<par[i]<<" "; cerr<<endl;

    for(int i = 0; i < 62; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (i == 0 ? par[j] : dp[i - 1][dp[i - 1][j]]);
        }
    }

    for(int i = 61; i >= 0; i--) {
        if(k >> i & 1) {
            for(int j = 1; j <= n; j++) {
                par[j] = dp[i][par[j]];
            }
        }
        // cerr<<"u: "<<u<<endl;
        // cout<<par[u]<<" ";
    }

    for(int i = 1; i <= n; i++) cout<<par[i]<<" ";
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