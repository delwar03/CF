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
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    int mx1 = 0, mx2 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]) {
            int j = i;
            while(j < n && a[j]) j++;
            mx1 = max(mx1, j - i);
            i = j - 1;
        }
    }
    for(int i = 0; i < n; i++) {
        if(b[i]) {
            int j = i;
            while(j < n && b[j]) j++;
            mx2 = max(mx2, j - i);
            i = j - 1;
        }
    }

    cout<<(mx1 == mx2 ? "Draw" : mx1 > mx2 ? "Om" : "Addy")<<endl;
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