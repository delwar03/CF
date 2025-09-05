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
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getXor(int n) {
    if(n < 0) return 0;
    if(n % 4 == 0) {
        return n;
    } else if(n % 4 == 1) {
        return 1;
    } else if(n % 4 == 2) {
        return n + 1;
    } else {
        return 0;
    }
}

void solve() {
    int l, r; cin >> l >> r;
    int a = 0, b = 0, c = getXor(r) ^ getXor(l - 1);
    
    for(int i = 0; i < 60; i++) {
        if(!(l >> i & 1)) continue;
        int now = l & ((1LL << i) - 1) , last = (1LL << i) - 1; 
        if(l + (last - now + 1) > r) a |= (1LL << i);
    }
    for(int i = 0; i < 60; i++) {
        if(l >> i & 1) {b |= (1LL << i); continue;}
        int now = l & ((1LL << i) - 1) , last = (1LL << i) - 1;
        if(l + (last - now + 1) <= r) {b |= (1LL << i); }
    }

    cout << a << " " << b << " " << c << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}