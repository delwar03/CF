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
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    sort(v.begin(), v.end());

    auto get = [&] (int skp) {
        vector<int> tmp;
        for(int i = 0; i < n; i++) {
            if(i == skp) continue;
            tmp.push_back(v[i]);
        }

        int ret = -INF, sz = (int) tmp.size();
        for(int i = 0; i < sz; i += 2) {
            if(i + 1 < sz) ret = max(ret, tmp[i + 1] - tmp[i]);
        }

        if(!sz) ret = 1;

        return ret;
    };

    int ans = INF;
    if(n & 1) {
        for(int i = 0; i < n; i++) {
            ans = min(ans, get(i));
        }
    } else {
        ans = get(-1);
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

/*
i/p: 
o/p: 
*/