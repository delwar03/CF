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
    int n, x, k; cin>>n>>x>>k;
    string s; cin>>s;
    int cnt = 0;
    for(int i = 0; i < n && k; i++) {
        x += (s[i] == 'R' ? +1 : -1);
        k--;
        if(x == 0) {cnt = 1; break; }
        // cerr<<"x: "<<x<<endl;
    }

    if(!k || !cnt) {cout<<cnt<<endl; return; }

    // cerr<<cnt<<endl;

    int sm = 0, id = -1;
    for(int i = 0; i < n; i++) {
        sm += (s[i] == 'R' ? +1 : -1);
        if(!sm) {id = i + 1; break;}
    }

    if(id == -1) {
        cout<<cnt<<endl;
    } else {
        cnt += k / id;
        cout<<cnt<<endl;
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