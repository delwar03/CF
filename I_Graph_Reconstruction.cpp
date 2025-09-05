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
    map<pii, int> mp;
    for(int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        --u, --v;
        mp[{u, v}] = mp[{v, u}] = 1;
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0LL);
    for(int i = 0; i < 2000; i++) {
        int f = 1;
        for(int j = 0; j < m; j++) {
            if(mp.count({ord[j], ord[(j + 1) % n]})) {f = 0; break; }
        }
        if(f) {
            for(int j = 0; j < m; j++) cout<<ord[j] + 1<<" "<<ord[(j + 1) % n] + 1<<endl;
            return;
        }
        random_shuffle(ord.begin(), ord.end());
    }
    cout<<-1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}