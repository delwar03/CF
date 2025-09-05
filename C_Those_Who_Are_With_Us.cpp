#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(auto &x : v) for(auto &y : x) cin>>y;

    auto f = [&] (int x) {
        vector<int> row[n], col[m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] > x + 1) return false;
                if(v[i][j] != x + 1) continue;
                row[i].push_back(j), col[j].push_back(i);
            }
        }

        int ct = 0;
        for(int i = 0; i < m; i++) ct += (sz(col[i]) > 0);
        if(ct <= 1) return true;

        for(int i = 0; i < n; i++) if(sz(row[i])) {
            int bad = 0;
            for(int j : row[i]) bad += (sz(col[j]) == 1);
            if(ct - bad <= 1) return true;
        }

        return false;
    };
    
    int lo = 0, hi = 105, best = -1;

    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(f(mid)) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout<<best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}