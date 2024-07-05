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
    vector<int> c(n), a(n), b(n);
    for(auto &x : c) cin>>x;
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    int cnt = 0, ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] == b[i]) {
            cnt = c[i] + 1;
        } else {
            if(cnt) {
                int p = abs(a[i] - b[i]);
                int q = cnt - p;
                cnt = max(q, p);
            }
            else cnt += abs(a[i] - b[i]);
            cnt += c[i] + 1;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}

/*
i/p: 
o/p: 
*/ 