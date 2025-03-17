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
    int ans = 0;
    vector<int> v(n + 1);
    iota(v.begin(), v.end(), 0LL);
    int b = 32 - __builtin_clz(n);
    // cerr<<"b: "<<b<<endl;
    if(n & 1) { // last &
        ans = n;
        swap(v[1], v[n - 2]);
        swap(v[3], v[n - 3]);
    } else {
        ans = (1LL << (__lg(n) + 1)) - 1;
        if(!(n & (n - 1))) {
            swap(v[1], v[n - 3]);
            swap(v[3], v[n - 4]);
        } else {
            swap(v[n - 2], v[n]);
            swap(v[n], v[(1LL << (b - 1)) - 1]);
        }
    }
    cout<<ans<<endl;
    for(int i = 1; i <= n; i++) cout<<v[i]<<" "; cout<<endl;
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

/*
i/p: 
o/p: 
*/