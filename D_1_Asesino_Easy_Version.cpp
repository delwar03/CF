#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
// #define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ask(i, j) == ask(j, i) -> 1 0

/*  
    i  ,  j
    knt, knt -> 1 1
    knt, knv -> 0 0
    knv, knt -> 0 0
    knv, knv -> 1 1

    knt, imp -> 1 0
    imp, knt -> 0 1

    knv, imp -> 0 1
    imp, knv -> 1 0

    (1, i) -> 1

*/

void solve() {
    int n; cin>>n;
    // string s; cin>>s;

    auto ask = [&] (int i, int j) {
        cout<<"? "<<i<<" "<<j<<endl;
        int x; cin>>x;
        return x;
    };

    auto ans = [&] (int i) {
        cout<<"! "<<i<<endl;
    };

    int x = 1, y = 2, r = -1;

    while(y <= n) {
        int r1 = ask(x, y), r2 = ask(y, x);
        if(r1 != r2) {
            r = r1;
            break;
        }
        x += 2;
        y += 2;
    }

    if(r == -1) {ans(n); return; }

    if(y == n) {
        if(ask(x, y - 2) == ask(y, y - 2)) {
            ans(r == 1 ? x : y);
        } else {
            ans(r == 1 ? y : x);
        }
    } else {
        if(ask(x, y + 1) == ask(y, y + 1)) {
            ans(r == 1 ? x : y);
        } else {
            ans(r == 1 ? y : x);
        }
    }
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