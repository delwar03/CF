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
    int n, k; cin>>n>>k;
    vector<int> v(n);
    int mx = 0, mn = INF;
    for(auto &x : v) {
        cin>>x;
        mx = max(mx, x);
        mn = min(mn, x);
    }

    if(mx == mn) {
        cout<<(mx == k ? 0 : 1)<<endl;
        return;
    }

    int l = 0, r = n - 1;
    while(l <= r && v[l] == k) l++;
    while(l <= r && v[r] == k) r--;

    int g = 0;
    mx = 0, mn = INF;
    for(int i = l; i <= r; i++) {
        g = __gcd(g, v[i]);
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }

    if(g % k == 0) {
        cout<<1<<endl;
    } else {
        cout<<(mx == mn ? 1 : 2)<<endl;
    }
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