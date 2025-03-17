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

// key idea: we gonna be buying all of the products
//           whose price <= x -> BS on x...

void solve() {
    int n, m; cin>>n>>m;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    sort(v.begin(), v.end());

    auto f = [&] (int x) {
        int sum = 0, cnt = 0;
        for(int i = 0; i < n; i++) if(v[i] <= x) {
            int k = (x + v[i]) / (2 * v[i]);
            sum = min(m + 1, sum + (int) min(2e18L, 1.0L * k * k * v[i]));
            cnt += k;
        }
        return make_pair(sum, cnt);
    };

    int lo = 0, hi = m + 1, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        auto [sum, cnt] = f(mid);
        if(sum <= m) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    assert(~best);
    
    auto [sum, cnt] = f(best);
    cnt += (m - sum) / (best + 1);

    cout<<cnt<<endl;
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