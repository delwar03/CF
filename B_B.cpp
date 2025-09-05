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
    int k, n, m; cin >> k >> n >> m;
    vector<int> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    vector<int> pos[2], neg[2];
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) pos[0].emplace_back(a[i]);
        else neg[0].emplace_back(-a[i]);
    }
    for(int i = 0; i < m; i++) {
        if(b[i] >= 0) pos[1].emplace_back(b[i]);
        else neg[1].emplace_back(-b[i]);
    }

    for(int i : {0, 1}) {
        sort(pos[i].rbegin(), pos[i].rend());
        sort(neg[i].rbegin(), neg[i].rend());
    }

    vector<int> cur;
    for(int i = 0; i < min(sz(pos[0]), sz(pos[1])); i++) {
        cur.push_back(pos[0][i] * pos[1][i]);
    }
    for(int i = 0; i < min(sz(neg[0]), sz(neg[1])); i++) {
        cur.push_back(neg[0][i] * neg[1][i]);
    }

    if(sz(cur) < k) {
        int rem = k - sz(cur), id1 = sz(pos[0]) > sz(pos[1]) ? 0 : 1, id2 = sz(neg[0]) > sz(neg[1]) ? 0 : 1;
        sort(pos[id1].begin(), pos[id1].end());
        sort(neg[id2].begin(), neg[id2].end());
        for(int i = 0; i < rem; i++) {
            cur.push_back(pos[id1][i] * -neg[id2][rem - i - 1]);
        }
    }

    int ans = 0;
    sort(cur.rbegin(), cur.rend());
    for(int i = 0; i < k; i++) ans += cur[i];
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}