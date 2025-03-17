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
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    o_set<int> st;
    vector<int> aa, bb;

    for(int i = n - 1; i >= 0; i--) {
        st.insert(a[i]);
        aa.push_back(st.order_of_key(a[i]));
    }
    st.clear();
    for(int i = n - 1; i >= 0; i--) {
        st.insert(b[i]);
        bb.push_back(st.order_of_key(b[i]));
    }

    vector<int> sum(n);

    for(int i = 0; i < n; i++) {
        int cur = sum[i] + aa[i] + bb[i];
        if(cur >= i + 1) {
            sum[i] = cur - (i + 1);
            if(i + 1 < n)
                sum[i + 1]++;
        } else {
            sum[i] = cur;
        }
    }

    // cerr<<"aa: ";
    // for(auto it : aa) cerr<<it<<" "; cerr<<endl;
    // cerr<<"bb: ";
    // for(auto it : bb) cerr<<it<<" "; cerr<<endl;
    // cerr<<"sum: ";
    // for(auto it : sum) cerr<<it<<" "; cerr<<endl;

    st.clear();
    for(int i = 0; i < n; i++) st.insert(i);

    vector<int> perm;

    for(int i = n - 1; i >= 0; i--) {
        int cur = *st.find_by_order(sum[i]);
        perm.push_back(cur);
        st.erase(cur);
    }

    for(auto it : perm) cout<<it<<" "; cout<<endl;

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