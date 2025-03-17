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
    int n, x, pos; cin>>n>>x>>pos;
    vector<int> v(n, 0);
    v[pos] = x;
    int ans = 1;
    int lo = 0, hi = n, best = -1, small = x - 1, big = n - x;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(mid <= pos) {
            best = mid;
            lo = mid + 1;
            if(mid != pos) {
                (ans *= small) %= mod;
                small -= 1;
                v[mid] = 1;
            }
        } else {
            hi = mid;
            (ans *= big) %= mod;
            big -= 1;
            v[mid] = 1;
        }
    }
    assert(best == pos);
    int cnt = count(v.begin(), v.end(), 0LL);
    for(int i = 1; i <= cnt; i++) (ans *= i) %= mod;

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