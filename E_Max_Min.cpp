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
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int mx = 0;
    for(int &x : v) {
        cin>>x;
        mx = max(mx, x);
    }

    sort(v.begin(), v.end());

    vector<int> BIT(mx + 10);

    auto add = [&] (int x, int val) {
        for(int i = x; i <= mx; i += i & -i) BIT[i] += val;
    };

    auto sum = [&] (int x) {
        int ret = 0;
        for(int i = x; i > 0; i -= i & -i) ret += BIT[i];
        return ret;
    };

    auto qur = [&] (int l, int r) {
        if(l > r) return 0LL;
        return sum(r) - sum(l - 1);
    };
    
    for(int x : v) add(x, +1);

    vector<int> dp(n);

    for(int i = 0; i < n; i++) {
        // i -> x(min)
        // j -> (x ... mx) => (x ... 2x - 1, 2x ... 3x - 1, 3x ... 4x - 1....)
        add(v[i], -1);
        if(i && v[i] == v[i - 1]) {
            dp[i] = dp[i - 1] - 1;
            continue;
        }
        for(int y = v[i]; y <= mx; y += v[i]) {
            dp[i] += qur(y, mx);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += dp[i];
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

/*
i/p: 
o/p: 
*/