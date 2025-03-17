#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    int n, m, k; cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    auto get = [&] (vector<int> v) {
        int n = sz(v);
        vector<int> ret(n + 1);
        for(int i = 0; i < n; i++) {
            if(!v[i]) continue;
            int j = i;
            while(j < n && v[j] == 1) j++;
            int len = j - i;
            for(int k = 1; k <= len; k++) {
                ret[k] += len - k + 1;
            }
            i = j - 1;
        }
        return ret;
    };

    auto f1 = get(a), f2 = get(b);

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(k % i == 0 && k / i <= m) {
            ans += f1[i] * f2[k / i];
        }
    }

    cout<<ans<<endl;
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