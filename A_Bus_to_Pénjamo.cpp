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
    int n, r; cin>>n>>r;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int ans = 0, cnt = 0, baki = 0;
    for(int i = 0; i < n; i++) {
        ans += (v[i] / 2) * 2;
        cnt += v[i] / 2;
        baki += v[i] % 2;
    }
    int cur = r - cnt;
    // cerr<<"ans: "<<ans<<", cnt: "<<cnt<<", cur: "<<cur<<", baki: "<<baki<<endl;
    if(cur >= baki) {
        ans += baki;
    } else {
        baki -= cur;
        ans += cur - baki;
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

/*
i/p: 
o/p: 
*/