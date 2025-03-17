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
    int n, k; cin>>n>>k;
    vector<int> g[n + 1];
    for(int i = 2; i <= n; i++) {
        int p; cin>>p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    vector<int> dep(n + 1);
    int cnt = 0;

    function<void(int, int, int)> dfs = [&] (int u, int p, int cur) {
        dep[u] = 1;
        for(auto v : g[u]) {
            if(v ^ p) {
                dfs(v, u, cur);
                dep[u] = max(dep[u], 1 + dep[v]);
            }
        }
        if(dep[u] == cur && u != 1 && p != 1) {dep[u] = 0; cnt++; }
    };

    int lo = 1, hi = n - 1, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        cnt = 0;
        dfs(1, 0, mid);
        if(cnt <= k) {
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

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}