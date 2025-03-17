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
    vector<int> v(n + 1);
    vector<int> mp[35], cur[35];
    int f = 1;
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        mp[__builtin_popcountll(v[i])].push_back(v[i]);
        cur[__builtin_popcountll(i)].push_back(i);
        if(__builtin_popcountll(v[i]) != __builtin_popcountll(i)) {
            f = 0;
        }
    }

    for(int i = 0; i < 35; i++) sort(mp[i].begin(), mp[i].end());
    for(int i = 0; i < 35; i++) {
        if(mp[i] != cur[i]) {
            f = 0;
        }
    }
    cout<<(f ? "Yes" : "No")<<endl;
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