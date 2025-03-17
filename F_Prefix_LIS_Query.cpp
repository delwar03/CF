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
    int n, q; cin>>n>>q;
    vector<int> v(n), tmp;
    for(auto &x : v) cin>>x;

    vector<pii> qur[n];
    for(int i = 0; i < q; i++) {
        int r, x; cin>>r>>x;
        --r;
        qur[r].push_back({x, i});
    }

    vector<int> ans(q);
    
    for(int i = 0; i < n; i++) {
        if(tmp.empty() || tmp.back() < v[i]) {
            tmp.push_back(v[i]);
        } else {
            int ind = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
            tmp[ind] = v[i];
        }
        for(auto [x, id] : qur[i]) ans[id] = upper_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
    }
    
    for(int x : ans) cout<<x<<endl;
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