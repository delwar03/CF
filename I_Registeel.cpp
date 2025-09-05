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
    string s; cin >> s;

    set<int> st;
    for(int i = 0; i + 1 < n; i++) if(s[i] ^ s[i + 1]) st.insert(i);

    while(q--) {
        int l, r; cin >> l >> r; l--, r--;
        while(l < r) {
            auto it = st.lower_bound(l);
            if(it == st.end() || *it + 1 > r) break;

            if(s[*it] > s[*it + 1]) {
                l = *it + 1;
            } else {
                r = *it;
            }
        }
        cout << l + 1 << endl;
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