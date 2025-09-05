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
    int n; string s; cin >> n >> s;
    set<int> pos[2];
    for(int i = 0; i < n; i++) pos[s[i] - '0'].insert(i);
    
    int id = 1;
    vector<int> ans(n);

    while(sz(pos[0]) && sz(pos[1])) {
        if(*pos[0].begin() < *pos[1].begin()) {
            int f = 0, cur = *pos[f].begin();
            while(sz(pos[f])) {
                auto it = pos[f].lower_bound(cur);
                if(it == pos[f].end()) break; 
                ans[*it] = id;
                cur = *it;
                pos[f].erase(it);
                f ^= 1;
            }
        } else {
            int f = 1, cur = *pos[f].begin();
            while(sz(pos[f])) {
                auto it = pos[f].lower_bound(cur);
                if(it == pos[f].end()) break;
                ans[*it] = id;
                cur = *it;
                pos[f].erase(it);
                f ^= 1;
            }
        }
        id += 1;
    }

    for(auto i : pos[0]) ans[i] = id++;
    for(auto i : pos[1]) ans[i] = id++;

    cout << *max_element(ans.begin(), ans.end()) << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}