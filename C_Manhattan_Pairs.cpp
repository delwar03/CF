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
    int n; cin >> n;
    vector<pii> pt(n + 1);
    vector<array<int, 3>> v(n);
    int ct = 1;
    for(auto &[x, y, id] : v) cin >> x >> y, id = ct++, pt[id] = {x, y};

    sort(v.begin(), v.end());

    sort(v.begin(), v.begin() + n / 2, [&] (const auto& A, const auto& B) {
        return A[1] < B[1];
    });
    sort(v.begin() + n / 2, v.end(), [&] (const auto& A, const auto& B) {
        return A[1] > B[1];
    });

    auto dist = [&] (int i, int j) {
        return abs(pt[i].F - pt[j].F) + abs(pt[i].S - pt[j].S);
    };

    for(int i = 0; i < n / 2; i++) {
        cout << v[i][2] << " " << v[i + n / 2][2] << endl;
    }
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