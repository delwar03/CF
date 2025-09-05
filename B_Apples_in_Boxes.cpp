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
    int n, k; cin>>n>>k;
    vector<int> v(n);
    int mx = 0, mn = INF, sm = 0;
    for(auto &x : v) cin>>x, mx = max(mx, x), mn = min(mn, x), sm += x;

    if(mx - mn > k) {
        for(int i = 0; i < n; i++) if(v[i] == mx) {v[i]--; break; }
        mx = 0; mn = INF;
        for(auto x : v) mx = max(mx, x), mn = min(mn, x);
        cerr<<mx<<" "<<mn<<endl;
        if(mx - mn > k) {
            cout<<"Jerry"<<endl;
        } else {
            cout<<(sm & 1 ? "Tom" : "Jerry")<<endl;
        }
    } else {
        cout<<(sm & 1 ? "Tom" : "Jerry")<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        cerr<<"Case "<<tc<<": \n";
        solve();
    }
}