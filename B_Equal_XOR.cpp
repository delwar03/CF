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
    vector<int> v1(n + 1, 0), v2(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        v1[x]++;
    }
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        v2[x]++;
    }
    vector<int> l, r;
    int m = 2 * k;
    for(int i = 1; i <= n; i++) {
        if(v1[i] == 2) {
            l.push_back(i);
            l.push_back(i);
            v1[i] -= 2;
            m -= 2;
        }
        if(m == 0) break;
    }
    int p = 2 * k;
    for(int i = 1; i <= n; i++) {
        if(v2[i] == 2) {
            r.push_back(i);
            r.push_back(i);
            v2[i] -= 2;
            p -= 2;
        }
        if(p == 0) break;
    }
    assert(m == p);
    if(m == 0 || p == 0) {
        for(auto it : l) cout<<it<<" "; cout<<endl;
        for(auto it : r) cout<<it<<" "; cout<<endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(v1[i] && v2[i]) {
            l.push_back(i);
            r.push_back(i);
            m--;
            p--;
        }
        if(m == 0 || p == 0) break;
    }
    for(auto it : l) cout<<it<<" "; cout<<endl;
    for(auto it : r) cout<<it<<" "; cout<<endl;
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