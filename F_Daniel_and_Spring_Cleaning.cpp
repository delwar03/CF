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

int dp[42][2][2];

void solve() {
    int l, r; cin>>l>>r;
    int a, b;

    function<int(int, int, int)> magic = [&] (int id, int f1, int f2) {
        if(a < 0) return 0LL;
        if(id < 0) return 1LL;
        int &ans = dp[id][f1][f2];
        if(~ans) return ans;
        ans = 0;
        for(int i : {0, 1}) {
            for(int j : {0, 1}) if(i + j < 2) {
                if(f1 && !(a >> id & 1) && i == 1) continue;
                if(f2 && !(b >> id & 1) && j == 1) continue;
                ans += magic(id - 1, f1 && ((a >> id & 1) == i), f2 && ((b >> id & 1) == j));
            }
        }
        return ans;
    };

    a = b = r;
    memset(dp, -1, sizeof dp);
    int ans = magic(40, 1, 1);
    a = l - 1;
    memset(dp, -1, sizeof dp);
    ans -= 2 * magic(40, 1, 1);
    a = b = l - 1;
    memset(dp, -1, sizeof dp);
    ans += magic(40, 1, 1);

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