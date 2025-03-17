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
    int n, k, q; cin>>n>>k>>q;
    vector<vector<int>> a(n, vector<int>(k));
    for(auto &x : a) for(auto &y : x) cin>>y;

    vector<vector<int>> b(n, vector<int>(k));

    for(int j = 0; j < k; j++) {
        for(int i = 0; i < n; i++) {
            b[i][j] = (i - 1 >= 0 ? b[i - 1][j] | a[i][j] : a[i][j]);
        }
    }

    // cerr<<"b: \n";
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < k; j++) {
    //         cerr<<b[i][j]<<" \n"[j == k - 1];
    //     }
    // }

    vector<vector<int>> tmp(k, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            tmp[j][i] = b[i][j];
        }
    }

    // cerr<<"tmp: \n";
    // for(int i = 0; i < k; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cerr<<tmp[i][j]<<" \n"[j == n - 1];
    //     }
    // }

    while(q--) {
        int m; cin>>m;
        int l = 0, r = n - 1;
        while(m--) {
            int j, c; char op; cin>>j>>op>>c;
            --j;

            if(op == '>') {
                int id = upper_bound(tmp[j].begin(), tmp[j].end(), c) - tmp[j].begin();
                l = max(l, id);
            } else {
                int id = lower_bound(tmp[j].begin(), tmp[j].end(), c) - tmp[j].begin() - 1;
                r = min(r, id);
            }
        }
        // cerr<<"l: "<<l<<", r: "<<r<<endl;
        cout<<(l <= r ? l + 1 : -1)<<endl;
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