#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// o_st.find_by_order(k) return kth element. 0 indexed.
// o_st.order_of_key(k) returns count of elements strictly less than k.
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
vector<int> dp(N, INF);

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int pos;
    for(int i = 0; i < n; i++) if(v[i] == k) {pos = i; break; }

    int l = 0, r = n;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        if(k >= v[m]) l = m;
        else r = m;
    }
    if(v[l] == k) cout<<0<<endl;
    else cout<<1<<endl<<pos + 1<<" "<<l + 1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> coins = {1, 3, 6, 10, 15};
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        for(auto it : coins) {
            if(i + it < N) {
                dp[i + it] = min(dp[i + it], dp[i] + 1);
            }
        }
    }
    // for(auto it : dp) cout<<it<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 