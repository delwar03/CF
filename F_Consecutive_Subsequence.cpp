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

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        mp[v[i]].push_back(i);
    }

    vector<int> dp(n, 1), par(n, -1);

    for(int i = 0; i < n; i++) {
        int prv = v[i] - 1;
        if(prv) {
            int ind = lower_bound(mp[prv].begin(), mp[prv].end(), i) - mp[prv].begin() - 1;
            if(ind >= 0) {
                if(1 + dp[mp[prv][ind]] > dp[i]) {
                    dp[i] = 1 + dp[mp[prv][ind]];
                    par[i] = mp[prv][ind];
                }
            }
        }
    }

    int mx = 0, pos = -1;
    for(int i = 0; i < n; i++) {
        if(dp[i] > mx) {
            mx = dp[i];
            pos = i;
        }
    }

    vector<int> ans;
    while(pos != -1) {
        ans.push_back(pos);
        pos = par[pos];
    }

    reverse(ans.begin(), ans.end());
    cout<<(int) ans.size()<<endl;
    for(auto it : ans) cout<<it + 1<<" "; cout<<endl;
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
