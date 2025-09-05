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
const int N = 2e3 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, x; cin>>n>>x;
    vector<int> v(n);
    int ct_1 = 0, ct_2 = 0;
    for(auto &x : v) cin>>x, ct_1 += (x % 3 == 1), ct_2 += (x % 3 == 2);
    if(ct_1 % 2 == ct_2 % 2) {
        if(ct_1 % 2 == 0) {
            if(x % 2 == 0) {
                cout<<"Giovana"<<endl;
            } else {
                cout<<(ct_1 + ct_2 != n ? "Giovana" : "Julia")<<endl;
            }
        } else {
            if(!x) {cout<<"Julia"<<endl; return; }
            if(x & 1) {
                cout<<"Giovana"<<endl;
            } else {
                cout<<(ct_1 + ct_2 != n ? "Giovana" : "Julia")<<endl;
            }
        }
    } else {
        cout<<"Julia"<<endl;
    }
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