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

int dp[15][256][2]; // (ind, mask, tight)

string getNum(int n) {
    string res = "";
    while(n) {
        res.push_back((char) (n % 7 + '0'));
        n /= 7;
    }
    if(!res.size()) res += "0";
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int n, m; cin>>n>>m;
    string A = getNum(n - 1);
    string B = getNum(m - 1);
    string s = A + ":" + B;

    function<int(int, int, int)> magic = [&] (int ind, int mask, int tight) {
        if(ind == s.size()) {
            return 1LL;
        }

        if(s[ind] == ':') return magic(ind + 1, mask, 1);

        int &ans = dp[ind][mask][tight];
        if(~ans) return ans;

        ans = 0;
        int mx = tight ? s[ind] - '0' : 6;

        for(int i = 0; i <= mx; i++) {
            if(mask & (1LL << i)) continue;
            ans += magic(ind + 1, mask | (1LL << i), tight & (i == mx));
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, 0, 1)<<endl;
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
