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
const int INF = 2e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;

    auto binPow = [&] (int a, int b) {
        int res = 1;
        for(int i = 0; i < b; i++) {
            if(1.0 * res * a > 2e18) return (int) 2e18;
            res *= a;
        }
        return res;
    };

    set<int> st;
    for(int b = 3; b <= 63; b++) {
        int a = 2;
        while(1) {
            int cur = binPow(a, b);
            if(cur > n) break;
            int sq = sqrtl(cur);
            if(sq * sq != cur) st.insert(cur);
            a++;
        }
    }
    int ans = (int) st.size();
    ans += (int) sqrtl(n);
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