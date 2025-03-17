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

    auto f = [&] (multiset<int> st) {
        int mn = *st.begin(), mx = *(--st.end());
        return 2 * mn > mx;
    };

    multiset<int> st;
    st.insert(v[0]);
    st.insert(v[1]);
    if(f(st)) {cout<<"YES"<<endl; return; }
    for(int i = 2; i < n; i++) {
        st.erase(st.find(v[i - 2]));
        st.insert(v[i]);
        if(f(st)) {cout<<"YES"<<endl; return; }
    }
    cout<<"NO"<<endl;
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