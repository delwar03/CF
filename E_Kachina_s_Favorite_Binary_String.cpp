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
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;

    auto ask = [&] (int l, int r) {
        if(r - l < 1) return 0LL;
        cout<<"? "<<l<<" "<<r<<endl;
        int x; cin>>x;
        return x;
    };

    auto print = [&] (string ans) {
        cout<<"! "<<ans<<endl;
    };

    int x = ask(1, n);
    if(!x) {
        print("IMPOSSIBLE");
    } else {
        string s;
        for(int i = 1; i < n; i++) {
            int y = ask(i + 1, n);
            if(y == x) {
                s += "1";
            } else {
                s += "0";
                if(!y) {
                    s += string(x, '1');
                    break;
                }
            }
            x = y;
        }
        while(sz(s) < n) s += "0";
        print(s);
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