#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[N][4];

void solve() {
    int n; cin>>n;
    string s, t; cin>>s>>t;

    auto id = [&] (char ch) {
        if(ch == 'A') return 0LL;
        if(ch == 'B') return 1LL;
        if(ch == 'C') return 2LL;
        else assert(false);
    };

    function<int(int, int)> magic = [&] (int ind, int prv) {
        if(ind == n) return 0LL;
        int &ans = dp[ind][prv];
        if(~ans) return ans;
        ans = INF;
        if(s[ind] == t[ind]) {
            ans = min(ans, magic(ind + 1, id(s[ind])));
        } else {
            for(int i = 0; i < 3; i++) {
                if(i == prv) continue;
                ans = min(ans, (id(s[ind]) != i) + magic(ind + 1, i));
            }
        }
        return ans;
    };

    memset(dp, -1, sizeof dp);
    cout<<magic(0, 3)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}