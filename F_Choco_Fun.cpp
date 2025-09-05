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
    int n, a, b; cin >> n >> a >> b;
    vector<pii> v(n);
    for(auto &[x, y] : v) cin >> x >> y;
    
    vector<pii> aa, bb;
    for(auto [x, y] : v) {
        if(x > y) {
            aa.push_back({x, y});
        } else {
            bb.push_back({x, y});
        }
    }

    int mx = 0;

    if(sz(aa) >= a && sz(bb) >= b) {
        sort(aa.begin(), aa.end(), [&] (pii a, pii b) {
            return a.F > b.F;
        });
        sort(bb.begin(), bb.end(), [&] (pii a, pii b) {
            return a.S > b.S;
        });
        for(int i = 0; i < a; i++) mx += aa[i].F;
        for(int i = 0; i < b; i++) mx += bb[i].S;
    } else {
        if(sz(aa) >= a) {
            sort(aa.begin(), aa.end(), [&] (pii a, pii b) {
                return a.F > b.F;
            });
            for(int i = 0; i < a; i++) mx += aa[i].F;
            for(int i = a; i < sz(aa); i++) bb.push_back(aa[i]);
            sort(bb.begin(), bb.end(), [&] (pii a, pii b) {
                return a.S > b.S;
            });
            for(int i = 0; i < b; i++) mx += bb[i].S;
        } else {
            sort(bb.begin(), bb.end(), [&] (pii a, pii b) {
                return a.S > b.S;
            });
            for(int i = 0; i < b; i++) mx += bb[i].S;
            for(int i = b; i < sz(bb); i++) aa.push_back(bb[i]);
            sort(aa.begin(), aa.end(), [&] (pii a, pii b) {
                return a.F > b.F;
            });
            for(int i = 0; i < a; i++) mx += aa[i].F;
        }
    }

    cout << mx << endl;
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