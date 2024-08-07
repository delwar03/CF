#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// o_st.find_by_order(k) return kth element. 0 indexed.
// o_st.order_of_key(k) returns count of elements strictly less than k.
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
vector<vector<int>> dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
}; // DURL

void solve() {
    string s; cin>>s;
    int n = s.size();
    int mx_len = 0;
    for(int len = 1; len <= n / 2; len++) {
        vector<int> dp(n, 0);
        for(int i = 0; i < n - len; i++) {
            if(s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?') {
                dp[i] = i == 0 ? 1 : dp[i - 1] + 1;
                if(dp[i] == len) {
                    mx_len = len;
                }
            }
        }
    }
    cout<<2 * mx_len<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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