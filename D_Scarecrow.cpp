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
    int n, k, l; cin>>n>>k>>l;
    k *= 2;
    l *= 2;
    vector<int> v(n);
    for(auto &x : v) cin>>x, x *= 2;

    int t = v[0], cur = k;

    for(int i = 1; i < n; i++) {
        if(cur >= l) break;
        if(v[i] <= cur) {
            v[i] = min(cur, v[i] + t);
            cur = v[i] + k;
        } else {
            v[i] = max(cur, v[i] - t);
            t += (v[i] - cur) / 2;
            cur = (v[i] + cur) / 2 + k;
        }
    }

    if(cur < l) t += (l - cur);

    cout<<t<<endl;
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