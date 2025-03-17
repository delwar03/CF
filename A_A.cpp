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

vector<int> di[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];

    vector<int> dp(n + 1, 1);

    for(int i = 1; i <= n; i++) {
        for(int j : di[i]) {
            dp[i] = max(dp[i], (v[j] < v[i] ? dp[j] : 0) + 1);
        }
    }

    // for(int i = 0; i <= n; i++) cerr<<dp[i]<<" \n"[i == n];

    cout<<*max_element(dp.begin(), dp.end())<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < N; i++) di[i].push_back(1);

    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i) {
            di[j].push_back(i);
        }
    }

    // for(int i = 1; i <= 10; i++) {
    //     cerr<<i<<" -> ";
    //     for(int j : di[i]) cerr<<j<<" "; cerr<<endl;
    // }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}