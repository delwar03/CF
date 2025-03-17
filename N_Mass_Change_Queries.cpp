#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    vector<vector<int>> g[n + 5];
    for(int i = 1; i <= n; i++) cin>>v[i];

    int q; cin>>q;

    for(int i = 1; i <= q; i++) {
        int l, r, x, y; cin>>l>>r>>x>>y;
        g[l].push_back({i, x, y});
        g[r + 1].push_back({i, x, x});
    }

    for(int i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            for(auto x : it)
                cerr<<x<<" ";
            cerr<<endl;
        } cerr<<endl;
    }

    int base = 1;
    while(base <= 2 * q) base <<= 1;

    vector<array<int, 105>> seg(2 * base + 1);

    for(auto &it : seg) {
        for(int i = 1; i <= 100; i++) {
            it[i] = i;
        }
    }

    auto upd = [&] (int i, int x, int y) {
        for(seg[i += base][x] = y, i >>= 1; i; i >>= 1) {
            int lc = 2 * i, rc = 2 * i + 1;
            for(int j = 1; j <= 100; j++) {
                seg[i][x] = seg[rc][seg[lc][x]];
            }
        }
    };

    for(int i = 1; i <= n; i++) {
        for(auto &vec : g[i]) {
            upd(vec[0], vec[1], vec[2]);
        }
    }

    for(int i = 1; i <= n; i++) cout<<seg[1][v[i]]<<" ";
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