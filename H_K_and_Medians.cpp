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
    int n, k, m; cin>>n>>k>>m;
    vector<int> b(m), vis(n + 1);
    for(auto &x : b) cin>>x, vis[x] = 1;

    if(k > 1 && (n - m) % (k - 1)) {cout<<"NO"<<endl; return; }

    sort(b.begin(), b.end());
    vector<int> c;
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        c.push_back(i);
    }

    int ct = (k - 1) / 2;

    for(auto x : b) {
        int c1 = upper_bound(c.begin(), c.end(), x) - c.begin();
        int c2 = sz(c) - (upper_bound(c.begin(), c.end(), x) - c.begin());
        if(c1 >= ct && c2 >= ct) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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