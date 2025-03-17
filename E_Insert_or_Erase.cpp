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
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    map<int, int> prv, nxt;
    nxt[0] = v[0];
    for(int i = 0; i < n; i++) {
        prv[v[i]] = (i - 1 >= 0 ? v[i - 1] : 0);
        nxt[v[i]] = (i + 1 < n ? v[i + 1] : 0);
    }

    int q; cin>>q;
    while(q--) {
        int t; cin>>t;
        if(t == 1) {
            int x, y; cin>>x>>y;
            int tmp = nxt[x];
            nxt[x] = y;
            prv[y] = x;
            nxt[y] = tmp;
            prv[tmp] = y;
        } else {
            int x; cin>>x;
            int tmp = prv[x], tmp2 = nxt[x];
            nxt[tmp] = tmp2;
            prv[tmp2] = tmp;
        }
    }

    int x = 0;
    while(nxt[x] != 0) {
        cout<<nxt[x]<<" ";
        x = nxt[x];
    }
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