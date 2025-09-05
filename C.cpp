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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    set<int> st1, st2;
    for(int i = 1; i + 1 < n; i++) {
        if(v[i - 1] < v[i] && v[i] > v[i + 1]) st1.insert(i);
        if(v[i - 1] > v[i] && v[i] < v[i + 1]) st2.insert(i);
    }

    int ans = 0;
    for(int i = 0; i + 1 < n; i++) if(v[i] < v[i + 1]) {
        auto it1 = st1.lower_bound(i + 1);
        auto it2 = st2.lower_bound(i + 1);
        if(it1 != st1.end() && it2 != st2.end()) {
            int mx = max(*it1, *it2);
            it1 = st1.lower_bound(mx + 1), it2 = st2.lower_bound(mx + 1);
            int mn = n - 1;
            if(it1 != st1.end()) mn = min(mn, *it1);
            if(it2 != st2.end()) mn = min(mn, *it2);
            ans += mn - mx;
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}