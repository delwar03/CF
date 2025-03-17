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
    vector<int> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    int prv = 0, f = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] < prv) {
            if(b[0] - a[i] < prv) {f = 0; break; }
            prv = b[0] - a[i];
        } else {
            prv = (b[0] - a[i] >= prv && b[0] - a[i] < a[i] ? b[0] - a[i] : a[i]);
        }
    }
    if(f) {cout<<"YES"<<endl; return; }

    prv = INF, f = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] > prv) {
            if(b[0] - a[i] > prv) {f = 0; break; }
            prv = b[0] - a[i];
        } else {
            prv = (b[0] - a[i] <= prv && b[0] - a[i] > a[i] ? b[0] - a[i] : a[i]);
        }
    }

    cout<<(f ? "YES" : "NO")<<endl;
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