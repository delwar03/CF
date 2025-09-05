#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int h, w, n; cin>>h>>w>>n;
    vector<int> R[h + 1], C[w + 1], row(h + 1), col(w + 1);
    for(int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        row[x] += 1; col[y] += 1;
        R[x].push_back(y), C[y].push_back(x);
    }

    int q; cin>>q;
    while(q--) {
        int t, x; cin>>t>>x;
        if(t == 1) {
            cout<<max(0LL, row[x])<<endl;
            for(int y : R[x]) col[y] -= 1;
            row[x] = 0;
            R[x].clear();
        } else {
            cout<<max(0LL, col[x])<<endl;
            for(int y : C[x]) row[y] -= 1;
            col[x] = 0;
            C[x].clear();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}