#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int sz = n * (n + 1) / 2;

    auto f = [&] (int x) {
        o_set<pii> st;
        st.insert({0, 0});
        int sm = 0, tot = 0;

        for(int i = 0; i < n; i++) {
            sm += (v[i] >= x ? +1 : -1);
            tot += st.order_of_key({sm, n});
            st.insert({sm, i});
        }

        return 2 * tot >= sz;
    };

    int lo = 1, hi = INF, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(f(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout<<best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}