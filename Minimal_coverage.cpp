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
    int m; cin>>m;
    vector<pii> segs;
    int l, r; cin>>l>>r;
    while(l || r) {
        segs.push_back({l, r});
        cin>>l>>r;
    }

    sort(segs.begin(), segs.end(), [&] (pii a, pii b) {
        if(a.F ^ b.F) return a.F < b.F;
        return a.S > b.S;
    });

    vector<pii> ans;
    int n = sz(segs), cur = 0, i = 0;
    while(cur < m) {
        pii mx = {cur - 1, -1};
        while(i < n && segs[i].F <= cur) {
            mx = max(mx, {segs[i].S, i});
            i++;
        }
        if(mx.F < cur) {cout<<0<<endl; return; }
        ans.push_back(segs[mx.S]);
        cur = mx.F;
    }

    cout<<sz(ans)<<endl;
    for(auto [a, b] : ans) cout<<a<<" "<<b<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
        if(t != tc) cout<<endl;
    }
}