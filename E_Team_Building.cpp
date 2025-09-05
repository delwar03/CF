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

void solve() {
    int n, p, k; cin>>n>>p>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    vector sk(n, vector<int>(p));
    for(auto &x : sk) for(auto &y : x) cin>>y;

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0LL);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
        return v[i] > v[j];
    });

    vector dp(n, vector<int>(1LL << p, -1));

    function<int(int, int)> magic = [&] (int ind, int mask) {
        int pc = __builtin_popcount(mask);
        if(ind == n) return (pc == p ? 0LL : -INF);
        int &ans = dp[ind][mask];
        if(~ans) return ans;
        ans = (ind - pc < k ? v[ord[ind]] : 0LL) + magic(ind + 1, mask);
        for(int i = 0; i < p; i++) if(!(mask >> i & 1)) ans = max(ans, sk[ord[ind]][i] + magic(ind + 1, mask | (1LL << i)));
        return ans;
    };

    cout<<magic(0, 0)<<endl;
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