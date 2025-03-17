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
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int pwr[12];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    auto getCnt = [&] (int x) {
        int tmp = x, ct = 0;
        while(tmp) {
            tmp /= 10;
            ct += 1;
        }
        return ct;
    };

    vector<int> cnt(12);
    int sm = 0;
    for(int i = 0; i < n; i++) {
        cnt[getCnt(v[i])] += 1;
        sm += v[i];
    }

    // for(int i = 0; i < 12; i++) cerr<<cnt[i]<<" "; cerr<<endl;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        sm -= v[i];
        cnt[getCnt(v[i])] -= 1;
        for(int j = 1; j <= 10; j++) {
            ans += (((v[i] * pwr[j]) % mod) * cnt[j]) % mod;
            ans %= mod;
        }
        ans += sm;
        ans %= mod;
        // cerr<<"ans: "<<ans<<endl;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pwr[0] = 1;
    for(int i = 1; i < 12; i++) pwr[i] = (10 * pwr[i - 1]) % mod;

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