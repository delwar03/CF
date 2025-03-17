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

vector<int> tmp = {1};
set<int> st;

void solve() {
    int n; cin>>n;
    int sm = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        sm += x;
        if(st.count(sm)) cnt += 1;
    }

    cout<<cnt<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x = 1;

    for(int i = 0; i <= 1005; i++) {
        tmp.push_back(x * 4 + 4);
        x += 2;
    }

    // cerr<<tmp.back();

    // for(int i = 0; i <= 10; i++) cerr<<tmp[i]<<" "; cerr<<endl;

    int sm = 0;

    for(auto it : tmp) {
        sm += it;
        st.insert(sm);
    }

    // for(auto it : st) cerr<<it<<" "; cerr<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}