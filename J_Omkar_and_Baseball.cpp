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
    vector<int> v(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) cin>>v[i], cnt += (v[i] != i);

    if(!cnt) {cout<<0<<endl; return; }

    int i = 1, j = n;
    while(i <= n && v[i] == i) i += 1;
    while(j >= 1 && v[j] == j) j -= 1;

    if(j - i + 1 == cnt) {cout<<1<<endl; return; }

    cout<<2<<endl;
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