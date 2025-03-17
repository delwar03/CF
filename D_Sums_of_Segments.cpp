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
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> pf(n + 1), pf2(n + 1);
    for(int i = 0; i < n; i++) pf[i + 1] = pf[i] + v[i];
    for(int i = 0; i < n; i++) pf2[i + 1] = pf2[i] + pf[i];

    // for(int i = 0; i < n; i++) cerr<<pf[i]<<" "; cerr<<endl;
    // for(int i = 0; i < n; i++) cerr<<p2[i]<<" "; cerr<<endl;

    auto f = [&] (int c) {
        return n * c - c * (c - 1) / 2;
    };

    auto bs = [&] (int x) {
        int l = 1, r = n, best = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(f(mid) <= x) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return best;
    };

    auto get = [&] (int i) {
        return 1 + (i - 1) * n - (i - 1) * (i - 2) / 2;
    };

    auto getSum = [&] (int i, int c) {
        return 0LL;
    };

    // 1,3,8,18,2,7,17,5,15,10

    auto qur = [&] (int l) {
        int L = bs(l), ret = 0;
        cerr<<"L: "<<L<<endl;
        ret = pf2[L];
        L++;
        int e1 = l - get(L) + 1;
        cerr<<"e1: "<<e1<<endl;
        ret += getSum(L, e1);
        return ret;
    };

    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<qur(r) - qur(l - 1)<<endl;
    }
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