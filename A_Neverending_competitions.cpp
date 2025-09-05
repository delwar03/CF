#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
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
    string s; cin>>s;
    map<string, int> mp;
    mp[s] = 0;
    vector<int> g[2 * n + 10];
    for(int i = 0, j = 1; i < n; i++) {
        string t; cin>>t;
        string x = t.substr(0, 3), y = t.substr(5);
        // cerr<<x<<" "<<y<<endl;
        if(!mp.count(x)) mp[x] = j++;
        if(!mp.count(y)) mp[y] = j++;

        g[mp[x]].push_back(mp[y]);
    }
    
    int cur = 0;
    while(sz(g[cur])) {
        int tmp = g[cur].back();
        g[cur].pop_back();
        cur = tmp;
    }

    cout<<(cur == 0 ? "home" : "contest")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}