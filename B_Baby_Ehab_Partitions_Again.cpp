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


int dp[105][200005];

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    int g = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        g = __gcd(g, v[i]);
        sum += v[i];
    }
    for(int i = 1; i <= n; i++) {
        dp[i][v[i]] = 1;
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(j - v[i] >= 0) dp[i][j] |= dp[i - 1][j - v[i]];
            dp[i][j] |= dp[i - 1][j];
        }
    }

    if((sum & 1) || dp[n][sum / 2] == 0) {
        cout<<0<<endl;
    } else {
        cout<<1<<endl;
        for(int i = 1; i <= n; i++) {
            v[i] /= g;
        }
        for(int i = 1; i <= n; i++) {
            if(v[i] & 1) {
                cout<<i<<endl;
                return;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 