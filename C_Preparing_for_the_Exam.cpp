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
    int n, m, k; cin>>n>>m>>k;
    vector<int> v(m), qq(k);
    for(auto &x : v) cin>>x;
    for(auto &x : qq) cin>>x;

    if(k == n) {
        cout<<string(m, '1')<<endl;
    } else if(k < n - 1) {
        cout<<string(m, '0')<<endl;
    } else {
        int bad = 0;
        for(auto it : qq) bad ^= it;
        for(int i = 1; i <= n; i++) bad ^= i;
        for(auto it : v) {
            cout<<(it == bad ? '1' : '0');
        } cout<<endl;
    }
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