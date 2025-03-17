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
const int INF = 1e10 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    vector<int> vals, a(n), b(n);
    for(auto &x : a) cin>>x, vals.push_back(x);
    for(auto &x : b) cin>>x, vals.push_back(x);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    int ans = 0;

    for(auto x : vals) {
        int c1 = n - (lower_bound(a.begin(), a.end(), x) - a.begin());
        int c2 = n - (lower_bound(b.begin(), b.end(), x) - b.begin());
        if(c2 - c1 <= k) ans = max(ans, x * c2);
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