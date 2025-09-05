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
    string t; cin >> t;
    int n, m = sz(t); cin >> n;
    vector<string> v(n);
    for(auto &x : v) cin >> x;

    vector<array<int, 3>> segs;
    for(int j = 0; j < n; j++) {
        string x = v[j];
        int sz = sz(x);
        if(sz > m) continue;
        string tmp;
        for(int i = 0; i < sz; i++) tmp.push_back(t[i]);
        if(tmp == x) segs.push_back({0, sz - 1, j + 1});
        for(int i = sz; i < m; i++) {
            tmp = tmp.substr(1);
            tmp.push_back(t[i]);
            if(tmp == x) segs.push_back({i - sz + 1, i, j + 1});
        }
    }

    sort(segs.begin(), segs.end(), [&] (const auto& A, const auto& B) {
        return A[0] == B[0] ? A[1] > B[1] : A[0] < B[0];
    });

    int cur = 0, j = 0;
    vector<pii> ans;
    while(cur < m) {
        int mx = cur - 1;
        pii pp = {-1, -1};
        while(j < sz(segs) && segs[j][0] <= cur) {
            if(segs[j][1] > mx) {
                mx = segs[j][1];
                pp = {segs[j][2], segs[j][0] + 1};
            }
            j++;
        }
        if(mx < cur) {cout << -1 << endl; return; }
        ans.push_back(pp);
        cur = mx + 1;
    }

    cout << sz(ans) << endl;
    for(auto [l, r] : ans) cout << l << " " << r << endl;
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