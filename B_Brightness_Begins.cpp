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

void chk(int n) {
    // cerr<<"n: "<<n<<endl;
    vector<int> tmp(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            tmp[j] = 1 - tmp[j];
        }
    }
    int cnt = 0;
    // cerr<<"tmp: ";
    for(int i = 1; i <= n; i++) {cnt += tmp[i];} //cerr<<endl;
    cerr<<"n: "<<n<<", cnt: "<<cnt<<endl;
}

void solve() {
    int k; cin>>k;

    auto f = [&] (int n) {
        int sq = sqrtl(n);
        return n - sq;
    };

    int l = 1, r = 1e18 + 2e9, best = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(f(mid) >= k) {
            best = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout<<best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // for(int i = 1; i <= 100; i++) chk(i);

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