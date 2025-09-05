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
    int n, q; cin >> n >> q;
    vector<int> v(n);
    int sm = 0;
    for(auto &x : v) cin >> x, sm += x;
    set<int> st;
    for(int i = 0; i < n; i++) if(v[i] == 1) st.insert(i);

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int s; cin >> s;
            if(s % 2 == sm % 2) {
                cout << (s <= sm ? "YES" : "NO") << endl;
            } else {
                if(!sz(st)) {cout << "NO" << endl; continue; }
                int l = *st.begin(), r = *st.rbegin();
                int mx = sm - min(2 * l + 1, 2 * (n - r - 1) + 1);
                cout << (s <= mx ? "YES" : "NO") << endl;
            }
        } else {
            int i, val; cin >> i >> val;
            --i;
            if(v[i] == 1) st.erase(i);
            sm -= v[i];
            v[i] = val;
            sm += v[i];
            if(v[i] == 1) st.insert(i);
        }
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