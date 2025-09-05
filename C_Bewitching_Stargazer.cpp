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

int n, k;

pii magic(int n) {
    if(n < k) return {0, 0};
    int m = (1 + n) >> 1;
    if(n & 1) {
        auto [sm, ct] = magic(m - 1);
        return {m + sm + sm + ct * m, 2 * ct + 1};
    } else {
        auto [sm, ct] = magic(m);
        return {sm + sm + ct * m, 2 * ct};
    }
}

void solve() {
    cin >> n >> k;
    cout << magic(n).F << endl;
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