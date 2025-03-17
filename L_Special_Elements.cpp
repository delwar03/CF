#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 64 * 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bitset<N> bst;

void solve() {
    bst.reset();
    int n; cin>>n;
    vector<int> v(n), pf(n + 1);
    for(auto &x : v) cin>>x;
    for(int i = 0; i < n; i++) pf[i + 1] = pf[i] + v[i];

    // for(auto it : pf) cerr<<it<<" "; cerr<<endl;
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            bst[pf[i + len] - pf[i]] = 1;
        }
    }

    // int mx = pf[n];
    // for(int i = 0; i <= mx; i++) cerr<<i<<" -> "<<bst[i]<<endl;

    int cnt = 0;
    for(int x : v) if(bst[x]) {
        cnt += 1;
    }

    cout<<cnt<<endl;
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