#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    int n, q; cin>>n>>q;
    string s; cin>>s;
    set<int> st;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) st.insert(i);
    }

    while(q--) {
        int typ, l, r; cin>>typ>>l>>r;
        --l; --r;
        if(typ == 1) {
            if(st.count(l)) {
                st.erase(l);
            } else if(l > 0) {
                st.insert(l);
            }
            if(st.count(r + 1)) {
                st.erase(r + 1);
            } else if(r + 1 < n) {
                st.insert(r + 1);
            }
        } else {
            auto it = st.upper_bound(l);
            if(it != st.end() && *it <= r) {
                cout<<"No"<<endl;
            } else {
                cout<<"Yes"<<endl;
            }
        }
    }
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