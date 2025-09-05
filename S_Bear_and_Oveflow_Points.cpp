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

    auto coln = [&] (pii a, pii b, pii c) {
        return (b.F - a.F) * (c.S - a.S) == (b.S - a.S) * (c.F - a.F);
    };

    for(int iter = 0; iter < 1000; iter++) {
        vector<pii> v;
        for(int i = 0; i < n; i++) v.push_back({rng() % 15, rng() % 15});
        int f = 1;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                for(int k = j + 1; k < n; k++) if(coln(v[i], v[j], v[k])) f = 0;
                
        if(f) {
            for(auto [a, b] : v) cout<<(a << 16)<<" "<<(b << 16)<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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