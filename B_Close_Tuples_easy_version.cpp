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

int Fact[N], invFact[N], Inv[N];

void solve() {
    int n, m = 3, k = 2; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int sz = n + k + 5;
    vector<int> BIT(sz + 1);

    auto add = [&] (int x, int val) {
        for(int i = x; i <= sz; i += i & -i) BIT[i] += val;
    };

    auto sum = [&] (int x) {
        int ret = 0;
        for(int i = x; i; i -= i & -i) ret += BIT[i];
        return ret;
    };

    auto qur = [&] (int l, int r) {
        if(l > r) return 0LL;
        return sum(r) - sum(l - 1);
    };

    sort(v.begin(), v.end());
    for(int x : v) add(x, +1);

    int ans = 0;

    for(int x : v) {
        add(x, -1);
        int cnt = qur(x, x + k);
        ans += cnt * (cnt - 1) / 2;
    }

    cout<<ans<<endl;
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