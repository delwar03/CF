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
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<vector<int>> dp(n, vector<int>(70, -1));

    function<int(int, int)> magic = [&] (int ind, int num) {
        if(ind == n) return (num == 0 ? 1LL : 0LL);
        int &ans = dp[ind][num];
        if(~ans) return ans;
        ans = 0;
        for(int i : {3, 6})
            ans |= magic(ind + 1, (10 * num + i) % 66);
        return ans;
    };

    string ans = "";

    function<void(int, int)> f = [&] (int ind, int num) {
        if(ind == n) return;
        if(magic(ind + 1, (10 * num + 3) % 66)) {
            ans += "3";
            f(ind + 1, (10 * num + 3) % 66);
        } else {
            ans += "6";
            f(ind + 1, (10 * num + 6) % 66);
        }
    };

    if(magic(0, 0)) {
        f(0, 0);
    } else {
        ans = "-1";
    }
    cout<<ans<<endl;
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

/*
i/p: 
o/p: 
*/