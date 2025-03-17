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
    int n, m, d; cin>>n>>m>>d;
    vector<int> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = -1;

    for(int x : b) {
        int ind = upper_bound(a.begin(), a.end(), x + d) - a.begin() - 1;
        if(ind >= 0) {
            if(abs(a[ind] - x) <= d)
                ans = max(ans, x + a[ind]);
        }
    }
    for(int x : a) {
        int ind = upper_bound(b.begin(), b.end(), x + d) - b.begin() - 1;
        if(ind >= 0) {
            if(abs(b[ind] - x) <= d)
                ans = max(ans, x + b[ind]);
        }
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