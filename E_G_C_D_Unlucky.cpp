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
    vector<int> pf(n), sf(n);
    for(auto &x : pf) cin >> x;
    for(auto &x : sf) cin >> x;

    auto f = [&] (int a, int b) {
        int g = gcd(a, b);
        return g == b;
    };

    int cur = pf[0];
    for(int i = 1; i < n; i++) {
        if(f(cur, pf[i])) {
            cur = pf[i];
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cur = sf[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        if(f(cur, sf[i])) {
            cur = sf[i];
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    cur = pf[n - 1];
    for(int i = 0; i < n; i++) {
        if(gcd(pf[i], sf[i]) != cur) {
            cout << "NO" << endl;
            return;
        }
    }

    auto v = pf;
    cur = pf[n - 1];
    for(int i = n - 1; i >= 0; i--) {
        if(cur != sf[i]) {
            if(sf[i] % cur) {cout << "NO" << endl; return; }
            int d = sf[i] / cur;
            v[i] *= d;
            cur = gcd(cur, v[i]);
        }
    }

    // for(int i : v) cerr << i << " "; cerr << endl;
    cur = 0;
    for(int i = 0; i < n; i++) {
        cur = gcd(cur, v[i]);
        if(cur != pf[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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