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

vector<int> dp(11);

void solve() {
    int n; cin>>n;
    cout<<(dp[n] ? "ALICE" : "BOB")<<endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    dp[1] = 1;
    
    for(int i = 2; i <= 10; i++) {
        for(int j : {1, 2}) {
            if(i - j >= 1 && !dp[i - j]) dp[i] = 1;
        }
    }

    for(int i = 1; i <= 10; i++) cerr<<i<<" -> "<<dp[i]<<endl; cerr<<endl;

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