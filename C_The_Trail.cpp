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
    int n, m; cin>>n>>m;
    string s; cin>>s;
    vector<int> Rsm(n), Csm(m);
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>v[i][j];
            Rsm[i] += v[i][j];
            Csm[j] += v[i][j];
        }
    }
    // for(auto it : Rsm) cerr<<it<<" "; cerr<<endl;
    // for(auto it : Csm) cerr<<it<<" "; cerr<<endl; cerr<<endl;

    int x = 0, y = 0;
    for(auto ch : s) {
        if(ch == 'R') {
            int tmp = -Csm[y];
            v[x][y] = tmp;
            Csm[y] += tmp;
            Rsm[x] += tmp;
            y += 1;
        } else {
            int tmp = -Rsm[x];
            v[x][y] = tmp;
            Csm[y] += tmp;
            Rsm[x] += tmp;
            x += 1;
        }
        // for(auto it : Rsm) cerr<<it<<" "; cerr<<endl;
        // for(auto it : Csm) cerr<<it<<" "; cerr<<endl; cerr<<endl;
    }
    v[x][y] = -Rsm[x];

    for(auto x : v) {
        for(auto y : x) cout<<y<<" "; cout<<endl;
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