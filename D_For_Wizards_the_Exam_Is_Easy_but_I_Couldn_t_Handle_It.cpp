#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

    int mx = 0, x = 1, y = 1;

    o_set<pii> st1, st2;

    for(int i = 0; i < n; i++) {
        st1.insert({v[i], i});
        int cur = 0, prv = 0;
        for(int j = i + 1; j < n; j++) {
            cur += st1.order_of_key({v[j], n});
            prv += st2.order_of_key({v[j], n});

            int tmp = st2.order_of_key({v[i], n});

            if(cur - (prv + tmp) > mx) {
                mx = cur - (prv + tmp);
                x = i + 1, y = j + 1;
            }

            st1.insert({v[j], j});
            st2.insert({v[j], j});
        }
        for(int j = i + 1; j < n; j++) st1.erase({v[j], j}), st2.erase({v[j], j});
        st2.insert({v[i], i});
    }

    cout<<x<<" "<<y<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}