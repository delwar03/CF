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
    vector<int> a(n), b(n);
    a[0] = 1;
    for(int i = 1; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // for(int i : a) cerr<<i<<" "; cerr<<endl;
    // for(int i : b) cerr<<i<<" "; cerr<<endl;

    auto f = [&] (int k) {
        for(int i = 0; i < k; i++) {
            if(a[i] >= b[n - k + i]) return false;
        }
        return true;
    };

    int lo = 0, hi = n, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(f(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout<<n - best<<endl;
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