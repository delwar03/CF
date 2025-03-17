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

struct Point {
    int x, y;
};

void solve() {
    int n, m; cin>>n>>m;
    vector<Point> v(n);
    for(auto &p : v) cin>>p.x>>p.y;

    if(m == 1) {cout<<"Infinity"<<endl; return; }

    auto col = [&] (int i, int j, int k) {
        int x1 = v[i].x, y1 = v[i].y, x2 = v[j].x, y2 = v[j].y, x3 = v[k].x, y3 = v[k].y;
        return ((x2 - x1) * (y3 - y2) == (x3 - x2) * (y2 - y1));
    };

    vector<vector<int>> vis(n, vector<int>(n, 0));
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(vis[i][j]) continue;
            vector<int> cur = {i, j};
            for(int k = j + 1; k < n; k++) {
                if(col(i, j, k)) {
                    cur.push_back(k);
                }
            }
            if((int) cur.size() >= m) ans++;
            for(int ii = 0; ii < (int) cur.size(); ii++) {
                for(int jj = 0; jj < (int) cur.size(); jj++) {
                    vis[cur[ii]][cur[jj]] = 1;
                }
            } 
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