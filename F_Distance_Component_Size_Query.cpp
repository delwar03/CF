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
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 3e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int q, k; cin>>q>>k;

    set<int> st;
    o_set<int> o_st;

    st.insert(INF);
    o_st.insert(INF);
    o_st.insert(-INF);

    auto add = [&] (int x, int y) {
        if(y - x > k)
            st.insert(y);
    };

    auto del = [&] (int x, int y) {
        if(y - x > k)
            st.erase(y);
    };

    for(int i = 0; i < q; i++) {
        int typ, x; cin>>typ>>x;
        if(typ == 1) {
            auto it = o_st.find(x);
            if(it == o_st.end()) { // insert
                it = o_st.lower_bound(x);
                del(*prev(it), *it);
                add(*prev(it), x);
                add(x, *it);
                o_st.insert(x);
            } else { // erase
                del(*prev(it), *it);
                del(*it, *next(it));
                add(*prev(it), *next(it));
                o_st.erase(it);
            }
        } else {
            auto it = st.upper_bound(x);
            // cerr<<"st: ";
            // for(auto x : st) cerr<<x<<" "; cerr<<endl;
            int ans = o_st.order_of_key(*it);
            ans -= o_st.order_of_key(*prev(it));
            cout<<ans<<endl;
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

/*
i/p: 
o/p: 
*/