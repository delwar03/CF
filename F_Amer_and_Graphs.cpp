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
    vector<pii> edges(n);
    for(auto &[u, v] : edges) {
        cin>>u>>v;
        if(u > v) swap(u, v);
    }

    map<multiset<pii>, int> mp;
    for(int i = 0; i < n; i++) {
        multiset<pii> st;
        for(int j = i; j < n; j++) {
            st.insert(edges[j]);
            mp[st] += 1;
        }
        // for(auto it : st) cerr<<it.F<<" "<<it.S<<endl;
    }

    int ans = 0;
    for(auto [a, b] : mp) {
        // for(auto it : a) cerr<<it.F<<" "<<it.S<<endl; cerr<<"b: "<<b<<endl<<endl;
        ans += b * (b - 1) / 2;
    }

    cout<<ans<<endl;
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