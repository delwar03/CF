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

int gcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = (a >= 0 ? +1 : -1), y = 0;
        return abs(a);
    }
    int x1, y1, g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

void solve() {
    int k;
    pii A, B; cin >> A.F >> A.S >> B.F >> B.S >> k;

    int dx = B.F - A.F, dy = B.S - A.S;
    int s, t, g = gcd(dx, dy, s, t);

    int x0 = -t, y0 = s;

    vector<pii> ans;

    while(sz(ans) < k) {
        pii C{x0 + A.F, y0 + A.S};
        if(C != A && C != B) ans.push_back(C);
        x0 += dx, y0 += dy;
    }

    for(auto [x, y] : ans) cout << x << " " << y << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}