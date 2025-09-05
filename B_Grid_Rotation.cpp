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
    int n; cin>>n;
    vector<string> S(n), T(n);
    for(auto &x : S) cin>>x;
    for(auto &x : T) cin>>x;

    auto get = [&] () {
        int cnt = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cnt += (S[i][j] != T[i][j]);
        return cnt;
    };

    auto rotate = [&] () {
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) swap(S[i][j], S[j][i]);
        for(auto &x : S) reverse(x.begin(), x.end());
    };

    int ans = get();
    rotate();
    ans = min(ans, 1 + get());
    rotate();
    ans = min(ans, 2 + get());
    rotate();
    ans = min(ans, 3 + get());

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}