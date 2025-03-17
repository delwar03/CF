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
const int N = 2e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> pos[N];

void solve() {
    int n; cin>>n;
    int mx = 0;
    for(int i = 0, x; i < n; i++) cin>>x, pos[x].push_back(i), mx = max(mx, x);

    int mn = INF;
    for(int i = 1; i <= mx; i++) if(sz(pos[i]) >= 2) {
        for(int j = 1; j < sz(pos[i]); j++) {
            mn = min(mn, pos[i][j] - pos[i][j - 1] + 1);
        }
    }

    cout<<(mn == INF ? -1LL : mn)<<endl;
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