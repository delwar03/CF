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
const int mxN = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int k, n; cin>>k>>n;
    vector<int> v(n + 1);
    int sm = 0;
    for(auto &x : v) cin>>x, (sm += x + mod) %= mod;
    
    auto binPow = [&] (int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b & 1) (ret *= a) %= mod;
            (a *= a) %= mod;
            b >>= 1;
        }
        return ret;
    };

    cout<<binPow(sm, k)<<endl;
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