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
    int n, q; cin>>n>>q;
    int ans = 0, l = 1, r = 2;
    while(q--) {
        char ch; int x; cin>>ch>>x;
        if(ch == 'L') {
            if(x >= l) {
                if(l <= r && r <= x) {
                    ans += l + (n - x);
                } else {
                    ans += (x - l);
                }
            } else {
                if(x <= r && r <= l) {
                    ans += (n - l) + x;
                } else {
                    ans += (l - x);
                }
            }
            l = x;
        } else {
            if(x >= r) {
                if(r <= l && l <= x) {
                    ans += r + (n - x);
                } else {
                    ans += (x - r);
                }
            } else {
                if(x <= l && l <= r) {
                    ans += (n - r) + x;
                } else {
                    ans += (r - x);
                }
            }
            r = x;
        }
    }
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