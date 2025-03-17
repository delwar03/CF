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
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    char g[n + 5][m + 5];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>>g[i][j];
        }
    }

    int a[n + 5][m + 5]{}, b[n + 5][m + 5]{}, c[n + 5][m + 5]{}, d[n + 5][m + 5]{};

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            a[i][j] = (g[i][j] == '+' ? 1 + a[i - 1][j] : 0);
        }
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= m; j++) {
            b[i][j] = (g[i][j] == '+' ? 1 + b[i + 1][j] : 0);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            c[i][j] = (g[i][j] == '+' ? 1 + c[i][j - 1] : 0);
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            d[i][j] = (g[i][j] == '+' ? 1 + d[i][j + 1] : 0);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(g[i][j] == '+') {
            int mn = min({a[i - 1][j], b[i + 1][j], c[i][j - 1], d[i][j + 1]});
            ans = max(ans, 4 * mn + 1);
        }
    }

    cout<<ans<<endl;
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