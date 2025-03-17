#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

int dp[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        vector<int> div;
        for(int j = 1; j * j <= v[i]; j++) {
            if(v[i] % j == 0) {
                div.push_back(j);
                if(j * j != v[i]) {
                    div.push_back(v[i] / j);
                }
            }
        }
        sort(div.rbegin(), div.rend());

        for(auto it : div) {
            dp[it] += dp[it - 1];
            dp[it] %= mod;
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i];
        ans %= mod;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
