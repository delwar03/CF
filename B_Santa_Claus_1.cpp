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
    int n, m, x, y; cin>>n>>m>>x>>y;
    --x; --y;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    string t; cin>>t;
    for(auto ch : t) {
        if(v[x][y] == '@' && !vis[x][y]) cnt++, vis[x][y] = 1;
        int nx = x, ny = y;
        if(ch == 'R') ++ny;
        else if(ch == 'L') --ny;
        else if(ch == 'U') --nx;
        else ++nx;
        if(v[nx][ny] != '#') x = nx, y = ny;
    }
    if(v[x][y] == '@' && !vis[x][y]) cnt++, vis[x][y] = 1;

    cout<<x + 1<<" "<<y + 1<<" "<<cnt<<endl;
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