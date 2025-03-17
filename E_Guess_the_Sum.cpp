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

// qur(i, j) = [2 ^ i * j ... 2 ^ i * (j + 1) - 1]

// 12 => 1100
// 4 + 8 => qur(2, 0) + qur(3, 0)
//         = [0, 3] + [0, 7]

void solve() {
    int n, l, r; cin>>n>>l>>r;

    auto ask = [&] (int i, int j) {
        cout<<"? "<<i<<" "<<j<<endl;
        int x; cin>>x;
        return x;
    };

    auto print = [&] (int x) {
        cout<<"! "<<x<<endl;
    };

    int sum = 0;
    for(int i = l; i <= r; i++) {
        int x = ask(0, i);
        sum = (sum + x) % 100;
    }
    print(sum);
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