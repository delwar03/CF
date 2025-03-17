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
    int n; cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(auto &x : v) for(auto &y : x) cin>>y;

    int cnt = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(v[i][j] < 0) {
        int mn = 0;
        for(int k = 0; i + k < n && j + k < n; k++) if(v[i + k][j + k] < 0) {
            mn = min(mn, v[i + k][j + k]);
            v[i + k][j + k] = 0;
        }
        cnt += -mn;
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