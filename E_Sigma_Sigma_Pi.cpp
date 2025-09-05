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

vector<int> prm = {2, 3, 5, 7, 11, 13, 17, 19};

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int ans = 0;
    vector<int> cnt(8), pf(1LL << 8);
    pf[0] = 1;

    for(int i = 0; i < n; i++) {

        int tmp = v[i];
        for(int j = 0; j < 8; j++) {
            while(tmp % prm[j] == 0) tmp /= prm[j], cnt[j]++;
        }

        for(int mask = 0; mask < (1LL << 8); mask++) {
            int cur = 1;
            for(int j = 0; j < 8; j++) if(!(mask >> j & 1)) (cur *= (cnt[j] + 1)) %= mod;
            (cur *= pf[mask]) %= mod;
            (ans += (__builtin_popcountll(mask) & 1 ? mod - 1 : 1) * cur) %= mod;
        }

        for(int mask = 0; mask < (1LL << 8); mask++) {
            int cur = 1;
            for(int j = 0; j < 8; j++) if(mask >> j & 1) (cur *= cnt[j]) %= mod;
            (pf[mask] += cur) %= mod;
        }
    }

    cout<<ans<<endl;
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