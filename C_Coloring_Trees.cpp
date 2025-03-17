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

int dp[105][105][105]; // (ind, last_color, seg_cnt)

void solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<int> col(n);
    vector<vector<int>> cost(n, vector<int>(m)); 
    for(auto &x : col) cin>>x;
    for(auto &x : cost) for(auto &y : x) cin>>y;

    function<int(int, int, int)> magic = [&] (int ind, int last, int cnt) {
        if(ind == n) {
            if(cnt == k) {
                return 0LL;
            }
            return INF;
        }

        int &ans = dp[ind][last][cnt];
        if(~ans) return ans;

        ans = INF;

        for(int i = 1; i <= m && cnt <= k; i++) {
            if(col[ind]) {
                if(col[ind] == last) {
                    ans = min(ans, magic(ind + 1, col[ind], cnt));
                } else {
                    ans = min(ans, magic(ind + 1, col[ind], cnt + 1));
                }
            } else {
                if(i == last) {
                    ans = min(ans, cost[ind][i - 1] + magic(ind + 1, i, cnt));
                } else {
                    ans = min(ans, cost[ind][i - 1] + magic(ind + 1, i, cnt + 1));
                }
            }
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    int ans = magic(0, 0, 0);
    cout<<(ans == INF ? -1 : ans)<<endl;
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
