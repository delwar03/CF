#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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

vector<int> cur = {2, 3, 5, 7};

int get(int n) {
    int ret = n;
    for(int mask = 1; mask < (1LL << 4); mask++) {
        int p = 1;
        for(int i = 0; i < 4; i++) if(mask >> i & 1) p *= cur[i];
        int cnt = n / p;
        ret += (__builtin_popcountll(mask) & 1 ? -1 : +1) * cnt;
    }
    return ret;
}

void solve() {
    int l, r; cin >> l >> r;
    cout << get(r) - get(l - 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}