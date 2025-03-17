#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    int n, d; cin>>n>>d;
    int mxDist = 0, l1 = 0, l2 = 0;
    for(int i = 0; i < n; i++) {
        char ch; int x; cin>>ch;
        if(ch == 'B') {
            cin>>ch>>x;
            mxDist = max(mxDist, max(x - l1, x - l2));
            l1 = l2 = x;
        } else {
            cin>>ch>>x;
            mxDist = max(mxDist, max(x - l1, x - l2));
            l2 = l1;
            l1 = x;
        }
    }
    mxDist = max(mxDist, max(d - l1, d - l2));
    cout<<mxDist<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}