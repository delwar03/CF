#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    string s; cin>>s;
    int n = s.size();
    s = "#" + s;
    vector<int> pf(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        pf[i] = pf[i - 1] + (s[i] == '1' ? 1 : -1);
    }

    map<int, int> mp;

    int ans = 0;

    for(int i = 0; i <= n; i++) {
        ans += (mp[pf[i]] * (n - i + 1)) % mod;
        ans %= mod;
        mp[pf[i]] += (i + 1);
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
