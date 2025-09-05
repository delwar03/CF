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

void solve() {
    int n, tc = 1;

    auto dist = [&] (array<double, 3> a, array<double, 3> b) {
        double dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
        return sqrt(dx * dx + dy * dy + dz * dz);
    };

    while(cin >> n && n) {
        cout<<"Case "<<tc++<<": ";
        double a, b, c; cin>>a>>b>>c;
        vector<array<double, 3>> far(n);
        for(auto &[a, b, c] : far) cin>>a>>b>>c;
        int mx = 933333;
        vector<int> cnt(n);
        for(int iter = 0; iter < mx; iter++) {
            array<double, 3> pt;
            pt[0] = double(rand()) * a / RAND_MAX;
            pt[1] = double(rand()) * b / RAND_MAX;
            pt[2] = double(rand()) * c / RAND_MAX;
            double mn = dist(far[0], pt);
            int id = 0;
            for(int i = 1; i < n; i++) {
                double cur = dist(far[i], pt);
                if(cur < mn) mn = cur, id = i;
            }
            cnt[id] += 1;
        }
        cout<<fixed<<setprecision(3);
        for(int i = 0; i < n; i++) {
            cout<<double(cnt[i]) / mx<<" \n"[i == n - 1];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(2333333);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cout<<"Case "<<tc<<": ";
        solve();
    }
}