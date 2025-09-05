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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;

    auto f = [&] (int x) {
        vector<int> pf(n);
        for(int i = 0; i < n; i++) pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0) + (v[i] >= x ? +1 : -1);
        int mn = 0;
        // for(int i : pf) cerr << i << " "; cerr << endl;
        for(int i = k - 1; i < n; i++) {
            if(mn <= pf[i]) return true;
            mn = min(mn, pf[i - (k - 1)]);
        }
        return false;
    };

    int lo = 1, hi = n, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(f(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    int mn = 0;
    vector<int> pf(n);
    for(int i = 0; i < n; i++) pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0) + (v[i] >= best ? +1 : -1);
    // for(int i : pf) cerr << i << " "; cerr << endl;
    set<pii> st;
    st.insert({0, -1});
    for(int i = k - 1; i < n; i++) {
        if(st.begin()->F <= pf[i]) {
            cout << best << " " << st.begin()->S + 2 << " " << i + 1 << endl;
            return;
        }
        st.insert({pf[i - (k - 1)], i - (k - 1)});
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