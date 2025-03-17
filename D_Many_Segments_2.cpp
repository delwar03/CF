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
    int n, m; cin>>n>>m;
    vector<int> L(n), R(n);
    vector<int> g[m + 1];
    for(int i = 0; i < n; i++) {
        cin>>L[i]>>R[i];
        g[L[i]].push_back(R[i]);
    }

    int ans = m * (m + 1) / 2, l = 0, r = m + 1;

    for(int i = 1; i <= m; i++) {
        if(g[i].empty()) continue;
        sort(g[i].begin(), g[i].end());
        auto it = lower_bound(g[i].begin(), g[i].end(), r);
        if(g[i][0] > r) continue;
        --it;
        ans -= (i - l) * (r - g[i][0]);
        l = max(l, i);
        r = min(r, g[i][0]);
        cerr<<"i: "<<i<<", ans: "<<ans<<endl;
    }

    cout<<ans<<endl;
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