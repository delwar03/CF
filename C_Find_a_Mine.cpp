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
const int N = 1e6;
const int INF = 1e15 + 10;
vector<int> dp(N, INF);

void solve() {
    int n, m; cin>>n>>m;
    auto ask = [&] (int i, int j) {
        cout<<"? "<<i<<" "<<j<<endl;
        int dist; cin>>dist;
        return dist;
    };

    auto print = [&] (int i, int j) {
        cout<<"! "<<i<<" "<<j<<endl;
    };

    int f = 0;
    int d1 = ask(1, 1);
    int mx_x = min(n, 1 + d1);
    int mx_y = min(m, 1 + d1);

    int d2 = ask(mx_x, d1 - mx_x + 2);
    int d3 = ask(d1 - mx_y + 2, mx_y);

    if(d2 % 2 == 0 && mx_x - d2 / 2 <= n && d1 - mx_x + 2 + d2 / 2 <= m) {
        int d4 = ask(mx_x - d2 / 2, d1 - mx_x + 2 + d2 / 2);
        f = (d4 != 0);
    } else {
        f = 1;
    }
    if(f) print(d1 - mx_y + 2 + d3 / 2, mx_y - d3 / 2);
    else print(mx_x - d2 / 2, d1 - mx_x + 2 + d2 / 2);
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