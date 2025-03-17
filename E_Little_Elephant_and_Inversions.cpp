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
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    o_set<pair<int, int>> left, right;
    int inv = 0;
    for(int i = 0; i < n; i++) {
        inv += (int) right.size() - right.order_of_key({v[i], n});
        right.insert({v[i], i});
    }

    int ans = 0, r = 0, cur = inv;
    for(int l = 0; l < n; l++) {
        while(l >= r) {
            cur -= right.order_of_key({v[r], -1});
            cur -= (int) left.size() - left.order_of_key({v[r], n});
            right.erase({v[r], r});
            r++;
        }
        
        cur += (int) left.size() - left.order_of_key({v[l], n});
        cur += right.order_of_key({v[l], -1});
        left.insert({v[l], l});

        while(r < n && cur > k) {
            cur -= right.order_of_key({v[r], -1});
            cur -= (int) left.size() - left.order_of_key({v[r], n});
            right.erase({v[r], r});
            r++;
        }

        ans += n - r;
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