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

void solve() {
    int n; cin>>n;
    auto ask = [&] (int i, int j) {
        cout<<"? "<<i<<" "<<j<<endl;
        int x; cin>>x;
        return !x;
    };

    auto ans = [&] (int i) {
        cout<<"! "<<i<<endl;
    };

    if(n == 3) {
        if(ask(1, 2) == ask(2, 1)) {
            ans(3);
        } else if(ask(2, 3) == ask(3, 2)) {
            ans(1);
        } else {
            ans(2);
        }
        return;
    }

    if(n & 1) {
        // (n - 2), (n - 1), n
        int x = ask(n - 2, n - 1), y = ask(n - 1, n), z = ask(n, n - 2);
        // 0 -> knt
        // 1 -> knv
        // 1 0 0
        // 1 1 1
        if(x ^ y ^ z) {
            if(x == ask(n - 1, n - 2)) {
                ans(n);
            } else if(y == ask(n, n - 1)) {
                ans(n - 2);
            } else {
                ans(n - 1);
            }
            return;
        }
        n -= 3;
    }
    while(n > 2) {
        // (n - 1), n
        int x = ask(n - 1, n), y = ask(n, n - 1);
        if(x ^ y) {
            ans((ask(n - 2, n - 1) ^ ask(n - 1, n - 2)) ? n - 1 : n);
            return;
        }
        n -= 2;
    }
    ans((ask(3, 2) ^ ask(2, 3)) ? 2 : 1);
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