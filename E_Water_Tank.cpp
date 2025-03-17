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
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];
    vector<int> left(n + 1), tmp;
    for(int i = 1; i <= n; i++) {
        while(tmp.size() && v[tmp.back()] <= v[i])
            tmp.pop_back();
        left[i] = (tmp.size() ? tmp.back() : 0);
        tmp.push_back(i);
    }
    // for(int i = 1; i <= n; i++) cerr<<left[i]<<" "; cerr<<endl;

    vector<int> dp(n + 1);

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[left[i]] + (v[i] * (i - left[i]));
    }

    for(int i = 1; i <= n; i++) cout<<dp[i] + 1<<" ";
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