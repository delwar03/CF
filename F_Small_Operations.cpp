#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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

void solve() {
    int x, y, k; cin>>x>>y>>k;
    int g = gcd(x, y);
    x /= g, y /= g;

    auto get = [&] (int n) {
        vector<int> di;
        for(int i = 1; i * i <= n; i++) if(n % i == 0) {
            di.push_back(i);
            if(i * i != n) di.push_back(n / i);
        }
        sort(di.begin(), di.end());
        int sz = sz(di);
        vector<int> dp(sz, INF);
        dp[0] = 0;
        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                if(di[j] % di[i] == 0 && di[j] / di[i] <= k)
                    dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp.back();
    };
    
    int a = get(x), b = get(y);
    cout<<(a == INF || b == INF ? -1 : a + b)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}