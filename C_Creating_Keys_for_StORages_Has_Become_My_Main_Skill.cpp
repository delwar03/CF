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
    int n, x; cin>>n>>x;
    vector<int> v;
    int orr = 0;
    for(int i = 0; i < n; i++) if((x | i) == x) {
        v.push_back(i);
        orr |= i;
    }

    if(orr != x && sz(v) == n) v.pop_back();
    while(sz(v) < n) v.push_back(x);

    for(int i = 0; i < n; i++) cout<<v[i]<<" \n"[i == n - 1];
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