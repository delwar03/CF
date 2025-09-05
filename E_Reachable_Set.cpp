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
    int n, m; cin>>n>>m;
    vector<int> g[n + 1];
    for(int i = 0; i < m; i++) {
        int x, y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    set<int> st;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            for(int v : g[i]) st.insert(v);
            cout<<sz(st)<<endl;
        } else {
            st.erase(i - 1);
            if(st.count(i)) {
                st.erase(i);
                for(int v : g[i]) if(v > i) st.insert(v);
                cout<<sz(st)<<endl;
            } else {
                st.insert(i);
                cout<<-1<<endl;
            }
        }
    }
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