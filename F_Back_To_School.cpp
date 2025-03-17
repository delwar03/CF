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
    int l, r; cin>>l>>r;

    auto get = [&] (int n) {
        int sm = 0;
        auto sum = [&] (int n) {
            return n * (n + 1) / 2;
        };
        for(int i = 1; i <= n; ) {
            int q = n / i, last = n / q;
            sm += (sum(last) - sum(i - 1)) * q;
            i = last + 1;
        }
        return sm;
    };

    cout<<get(r) - get(l - 1)<<endl;
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