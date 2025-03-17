#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) (x.size())


// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template<typename T> using o_set = tree<T, null_type, std::less<T>, 
// rb_tree_tag, tree_order_statistics_node_update>;

string tmp = "aeiou";
map<char, int> mp;


const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;


void solve() {
    int n; cin>>n;
    string s; cin>>s;
    mp['a'] = 0;
    mp['e'] = 1;
    mp['i'] = 2;
    mp['o'] = 3;
    mp['u'] = 4;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(35, vector<int>(6, INF)));

    for(int i = 0; i < 32; i++) for(int j = 0; j <= 5; j++) dp[n][i][j] = 0;

    for(int ind = n - 1; ind >= 0; ind--) {
        for(int mask = 0; mask < 32; mask++) {
            for(int prv = 0; prv < 5; prv++) {
                for(int op = 0; op <= 4; op++) {
                    int cur = (mp[s[ind]] + op) % 5;
                    if((cur != prv) && (mask & (1LL << cur))) continue;
                    dp[ind][mask][prv] = min(dp[ind][mask][prv], op + dp[ind + 1][mask | (1LL << cur)][cur]);
                }
            }
        }
    }

    cout<<dp[0][0][4]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cout<<"Case "<<tc<<":";
        solve();
    }
}