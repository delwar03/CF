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
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    // vector<int> pf1(n), pf2(n), ord(n);
    // iota(ord.begin(), ord.end(), 0LL);

    // sort(ord.begin(), ord.end(), [&] (int i, int j) {
    //     if(a[i] != a[j]) return a[i] > a[j];
    //     return b[i] < b[j];
    // });

    // for(int i = 0; i < n; i++) {
    //     pf1[i] = a[ord[i]] + (i - 1 >= 0 ? pf1[i - 1] : 0);
    // }
    // for(int i = n - 1; i >= 0; i--) {
    //     pf2[i] = b[ord[i]] + (i + 1 < n ? pf2[i + 1] : 0);
    // }

    // // for(auto it : pf1) cerr<<it<<" "; cerr<<endl;
    // // for(auto it : pf2) cerr<<it<<" "; cerr<<endl;


    // int ans = -INF;

    // for(int i = 0; i < n; i++) {
    //     ans = max(ans, pf1[i] + pf2[i]);
    // }

    // for(int i = 0; i < n; i++) cerr<<a[ord[i]]<<" "<<b[ord[i]]<<endl; cerr<<endl;

    // cout<<ans<<endl;

    // sort(ord.begin(), ord.end(), [&] (int i, int j) {
    //     if(b[i] != b[j]) return b[i] < b[j];
    //     return a[i] > a[j];
    // });

    // pf1 = vector<int>(n);
    // pf2 = vector<int>(n);

    // for(int i = 0; i < n; i++) {
    //     pf1[i] = a[ord[i]] + (i - 1 >= 0 ? pf1[i - 1] : 0);
    // }
    // for(int i = n - 1; i >= 0; i--) {
    //     pf2[i] = b[ord[i]] + (i + 1 < n ? pf2[i + 1] : 0);
    // }

    // for(int i = 0; i < n; i++) {
    //     ans = max(ans, pf1[i] + pf2[i]);
    // }

    // for(int i = 0; i < n; i++) cerr<<a[ord[i]]<<" "<<b[ord[i]]<<endl;

    // cout<<ans<<endl;

    int ans = -INF;

    for(int i = 0; i < n; i++) {
        int sm = a[i] + b[i];
        for(int j = 0; j < n; j++) if(i ^ j) {
            sm += max(a[j], b[j]);
        }
        ans = max(ans, sm);
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