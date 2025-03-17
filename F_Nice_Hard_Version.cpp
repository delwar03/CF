#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[N][2][2];

void solve() {
    int n; string s; cin>>n>>s;
    string tmp = s;
    int sz = 0;

    function<int(int, int, int)> magic = [&] (int ind, int tight, int start) {
        if(ind == sz) return start;
        int &ans = dp[ind][tight][start];
        if(~ans) return ans;
        ans = 0;
        int mx = tight ? s[ind] - '0' : 9;
        for(int i : {0, 6, 9}) {
            if(i > mx) continue;
            if(i) {
                ans += magic(ind + 1, tight & (i == mx), 1);
            } else if(!start) {
                ans += magic(ind + 1, tight & (i == mx), 0);
            }
        }
        return ans;
    };

    auto getCnt = [&] (int n) {
        vector<int> cnt(n);
        for(int i = 0; i < n; i++) {
        memset(dp, -1, sizeof dp);
            sz += 1;
            cnt[i] = magic(0, 1, 0);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += cnt[i];
            cerr<<cnt[i]<<" \n"[i == n - 1];
        }
        // cerr<<"ans: "<<ans<<endl;
        return ans;
    };

    cout<<getCnt(n)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}