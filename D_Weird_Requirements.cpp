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
    int n, x, y; cin>>n>>x>>y;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    if(y % x) {cout<<-1<<endl; return; }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if((v[i] % x) || (y % v[i])) cnt += 1;
    }

    if(cnt == 0) {
        int g = 0, l = 1;
        for(auto it : v) {
            g = __gcd(g, it);
            l = lcm(l, it);
        }
        cerr<<g<<" "<<l<<endl;
        if((g != x) || (l != y)) {
            for(auto it : v) {
                cnt += (it != x) && (it != y);
            }
        }
    }

    cout<<cnt<<endl;
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