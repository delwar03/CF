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
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> tmp, bk;

    for(int i = 0; i < n; i++) {
        while(sz(tmp) && tmp.back() > v[i]) {
            bk.push_back(tmp.back() + 1);
            tmp.pop_back();
        }
        tmp.push_back(v[i]);
    }

    sort(bk.begin(), bk.end());

    while(sz(bk) && sz(tmp) && tmp.back() > bk[0]) {
        bk.push_back(tmp.back() + 1);
        tmp.pop_back();
    }

    sort(bk.begin(), bk.end());

    for(auto it : tmp) cout<<it<<" ";
    for(auto it : bk) cout<<it<<" "; cout<<endl;
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