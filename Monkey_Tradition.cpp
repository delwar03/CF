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
    vector<int> P(n), R(n);
    for(int i = 0; i < n; i++) cin>>P[i]>>R[i];

    // for(int i = 0; i < n; i++) cerr<<P[i]<<" "<<R[i]<<endl; cerr<<endl;

    auto e_gcd = [&] (int a, int b) {
        array<int, 3> x = {1, 0, a}, y = {0, 1, b};
        while(y[2] > 0) {
            int k = x[2] / y[2];
            for(int i = 0; i < 3; i++) x[i] -= k * y[i];
            swap(x, y);
        }
        return x;
    };

    auto inv = [&] (int a, int b) {
        auto [x, y, g] = e_gcd(a, b);
        assert(g == 1);
        x %= b;
        return x + (x < 0) * b;
    };

    int ans = 0, md = accumulate(P.begin(), P.end(), 1LL, multiplies<int>());

    for(int i = 0; i < n; i++) {
        int mi = md / P[i], a = inv(mi, P[i]);
        (ans += mi * a % md * R[i]) %= md;
    }

    cout<<ans<<endl;
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