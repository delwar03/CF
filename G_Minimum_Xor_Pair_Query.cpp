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
    int q; cin >> q;
    multiset<int> cur, st;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int x; cin >> x;
            auto it = cur.insert(x);
            if(it != cur.begin()) st.insert(*prev(it) ^ x);
            if(next(it) != cur.end()) st.insert(*next(it) ^ x);
            if(it != cur.begin() && next(it) != cur.end()) st.erase(st.find(*prev(it) ^ *next(it)));
        } else if(t == 2) {
            int x; cin >> x;
            auto it = cur.find(x);
            if(it != cur.begin()) st.erase(st.find(*prev(it) ^ x));
            if(next(it) != cur.end()) st.erase(st.find(*next(it) ^ x));
            if(it != cur.begin() && next(it) != cur.end()) st.insert(*prev(it) ^ *next(it));
            cur.erase(it);
        } else {
            cout << *st.begin() << endl;
        }
        // for(int i : cur) cerr << i << " "; cerr << endl;
        // for(int i : st) cerr << i << " "; cerr << endl; cerr << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}