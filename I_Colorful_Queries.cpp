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
    vector<int> v(n + 1), pos(n + 1, -1);
    o_set<int> st;
    for(int i = 1; i <= n; i++) {
        cin >> v[i]; 
        if(pos[v[i]] == -1) pos[v[i]] = i;
        st.insert(i);
    }

    while(q--) {
        int x; cin >> x;
        int cur = st.order_of_key(pos[x]);
        cout << cur + 1 << endl;
        st.erase(pos[x]);
        pos[x] = *st.begin() - 1;
        st.insert(pos[x]);
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