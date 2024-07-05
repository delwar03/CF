#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n + 1);
    map<int, int> in_a;
    for(auto &x : a) {cin>>x; in_a[x]++; }
    for(auto &x : b) {cin>>x; }
    int ans = INF;
    for(int i = 0; i < n; i++) {
        int mx = max(a[i], b[i]), mn = min(a[i], b[i]);
        ans = min(ans, abs(mx - b[n]));
        ans = min(ans, abs(mn - b[n]));
        if(mn <= b[n] && b[n] <= mx) {
            ans = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    cout<<1 + ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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