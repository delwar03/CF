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
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin>>n>>m;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    auto valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    vector<vector<int>> dp(n, vector<int>(m, -1));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '?') dp[i][j] = 0;
        }
    }

    function<int(int, int)> magic = [&] (int i, int j) {
        if(!valid(i, j)) return 1LL;
        int &ans = dp[i][j];
        if(~ans) return ans;
        ans = 0;
        int ni = i, nj = j;
        if(v[i][j] == 'U') {
            ni -= 1;
        } else if(v[i][j] == 'D') {
            ni += 1;
        } else if(v[i][j] == 'L') {
            nj -= 1;
        } else if(v[i][j] == 'R') {
            nj += 1;
        }
        ans |= magic(ni, nj);
        return ans;
    };

    int cnt = 0, ans = n * m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(magic(i, j)) {
                cnt++;
            }
        }
    }

    // cerr<<"cnt: "<<cnt<<endl;

    ans -= cnt;
    cnt = 0;

    auto chk = [&] (int i, int j) {
        if(i - 1 >= 0 && (!magic(i - 1, j))) return true;
        if(i + 1 < n && (!magic(i + 1, j))) return true;
        if(j - 1 >= 0 && (!magic(i, j - 1))) return true;
        if(j + 1 < m && (!magic(i, j + 1))) return true;
        return false;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '?') {
                if(!chk(i, j)) {
                    cnt++;
                }
            }
        }
    }

    ans -= cnt;

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