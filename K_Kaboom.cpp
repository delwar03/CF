#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
// #define endl '\n'
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
    int n; cin >> n;
    int bestL = -1, bestR = -1;
    
    int l = 1, r = n;
    for(int i = 9; i >= 0; i--) {
        int m = l + (1LL << i);
        if(m > r) continue;
        cout << "? " << r - m + 1 << " ";
        for(int j = m; j <= r; j++) cout << j << " "; cout << endl;
        string x; cin >> x;
        if(x == "Kaboom") l = m;
    }
    for(int i = 9; i >= 0; i--) {
        int m = r - (1LL << i);
        if(m < l) continue;
        cout << "? " << m - l + 1 << " ";
        for(int j = l; j <= m; j++) cout << j << " "; cout << endl;
        string x; cin >> x;
        if(x == "Kaboom") r = m;
    }


    cout << "! " << l << " " << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}