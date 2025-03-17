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
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    while(q--) {
        int l, r; cin>>l>>r;
        if(r - l >= 1005) {cout<<0<<endl; continue; } 
        vector<int> tmp;
        for(int i = l; i <= r; i++) tmp.push_back(v[i]);
        sort(tmp.begin(), tmp.end());
        int ans = INF, sz = sz(tmp);
        for(int i = 1; i < sz; i++) {
            ans = min(ans, tmp[i] - tmp[i - 1]);
        }
        cout<<ans<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": \n";
        solve();
    }
}