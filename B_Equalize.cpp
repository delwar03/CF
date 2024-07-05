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
    int n; cin>>n;
    set<int> st;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        st.insert(x);
    }
    vector<int> v;
    for(auto it : st) v.push_back(it);
    // cerr<<"v: ";
    // for(auto it : v) cerr<<it<<" "; cerr<<endl;

    int m = v.size();
    int ans = 1, cnt = 1;
    int i = 0, j = 0;
    while(i < m && j < m) {
        if(v[j] - v[i] >= n) {
            ans = max(ans, j - i);
            i++;
            // i = j;
        } else {
            j++;
        }
        // cerr<<v[i]<<" "<<v[j]<<endl;
        // cerr<<"ans: "<<ans<<endl;
    }
    if(i != j) ans = max(ans, j - i);
    cout<<ans<<endl;
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