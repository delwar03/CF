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
    int l, r; cin>>l>>r;

    int a = 0, b = 0;

    for(int i = 60; i >= 0; i--) {
        if(a + (1LL << i) <= r && b + (1LL << i) - 1 >= l) a |= (1LL << i);
        else if(b + (1LL << i) <= r && a + (1LL << i) - 1 >= l) b |= (1LL << i);
        else if(a + (1LL << i) - 1 >= l && b + (1LL << i) - 1 >= l) a = a, b = b;
        else a |= (1LL << i), b |= (1LL << i);
    }

    cout<<(a ^ b)<<endl;
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