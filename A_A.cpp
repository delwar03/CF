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
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    set<pii> st1, st2;
    for(int i = n - 1; i >= 0; i--) {
        if(sz(st1) && v[i] + i > st1.begin()->F) {
            cout << "YES\n" << i + 1 << " " << st1.begin()->S + 1 << endl;
            return;
        }
        if(sz(st2) && v[i] - i < st2.rbegin()->F) {
            cout << "YES\n" << i + 1 << " " << st2.rbegin()->S + 1 << endl;
            return;
        }
        st1.insert({v[i] + i, i});
        st2.insert({v[i] - i, i});
    }
    st1.clear();
    st2.clear();
    for(int i = 0; i < n; i++) {
        if(sz(st1) && v[i] + i < st1.rbegin()->F) {
            cout << "YES\n" << i + 1 << " " << st1.rbegin()->S + 1 << endl;
            return;
        }
        if(sz(st2) && v[i] - i > st2.begin()->F) {
            cout << "YES\n" << i + 1 << " " << st2.begin()->S + 1 << endl;
            return;
        }
        st1.insert({v[i] + i, i});
        st2.insert({v[i] - i, i});
    }
    
    cout << "NO" << endl;
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