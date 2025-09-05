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
const double PI = acos(-1.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    double R, N;
    cout << fixed << setprecision(10);
    while(cin >> R >> N) {
        if(N == 1) {cout << R << " " << 0.0 << " " << 0.0 << endl; continue; }
        double theta = PI / N, r = R * sin(theta) / (1 + sin(theta));
        // cerr << r << endl;
        double E = 0.5 * R * R * theta;
        E -= 0.5 * r * r / tan(theta);
        E -= 0.5 * r * r * (PI / 2 + theta);
        E *= 2 * N;
        double I = PI * R * R - N * PI * r * r - E;

        cout << r << " " << I << " " << E << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}