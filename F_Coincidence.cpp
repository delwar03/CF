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
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[70][2][2][2];

void solve() {
    vector<pii> pt(2); cin>>pt[0].F>>pt[0].S;
    pt[1] = pt[0];
    vector<int> cur(2);

    function<int(int, int, int, int)> magic = [&] (int id, int f1, int f2, int f3) {
        if(id < 0) return f3;
        int &ans = dp[id][f1][f2][f3];
        if(~ans) return ans;
        ans = 0;
        for(int x : {0, 1}) {
            for(int y : {0, 1}) {
                if(x == 0 && y == 1) continue;
                if(f1 && !(cur[0] >> id & 1) && x == 1) continue;
                if(f2 && !(cur[1] >> id & 1) && y == 1) continue;
                if(!f3 && x == 1 && y == 0) continue;
                (ans += magic(id - 1, f1 && ((cur[0] >> id & 1) == x), f2 && ((cur[1] >> id & 1) == y), f3 || (x & y))) %= mod;
            }
        }
        return ans;
    };

    int ans = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) cur[j] = ((i >> j & 1) ? pt[j].S : pt[j].F - 1);
        memset(dp, -1, sizeof dp);
        (ans += (__builtin_popcount(i) & 1) ? -magic(62, 1, 1, 0) + mod : magic(62, 1, 1, 0)) %= mod;
    }
    cout<<ans<<endl;
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