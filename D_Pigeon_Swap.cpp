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
    int n, q; cin>>n>>q;
    vector<int> p(n + 1), id(n + 1), inv(n + 1);
    for(int i = 1; i <= n; i++) p[i] = id[i] = inv[i] = i;

    while(q--) {
        int t; cin>>t;
        if(t == 1) {
            int a, b; cin>>a>>b;
            p[a] = id[b];
        } else if(t == 2) {
            int a, b; cin>>a>>b;
            swap(id[a], id[b]);
            swap(inv[id[a]], inv[id[b]]);
        } else {
            int a; cin>>a;
            cout<<inv[p[a]]<<endl;
        }
    }
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