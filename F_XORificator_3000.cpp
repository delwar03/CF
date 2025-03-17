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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int l, r, i, k; cin>>l>>r>>i>>k;

    auto f = [&] (int n) {
        if(n < 0) return 0LL;
        if(n % 4 == 0) return n;
        if(n % 4 == 1) return 1LL;
        if(n % 4 == 2) return n + 1LL;
        else return 0LL;
    };

    auto xorr = [&] (int n) {
        int ans = f(n);
        int l = 0, r = (1LL << (62 - i)), best = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int x = (mid << i) + k;
            if(x <= n) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // cerr<<"best: "<<best<<endl;
        ans ^= f(best) << i;
        if((best + 1) & 1) ans ^= k;

        return ans;
    };

    int ans = xorr(r) ^ xorr(l - 1);

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

/*
i/p: 
o/p: 
*/