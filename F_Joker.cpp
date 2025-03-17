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
    int n, m, q; cin>>n>>m>>q;
    set<pii> prv = {{m, m}};
    while(q--) {
        int x; cin>>x;
        set<pii> cur;
        for(auto [l, r] : prv) {
            if(x < l) {
                if(l - 1 >= 1)
                    cur.insert({l - 1, r});
            }
            if(x > r) {
                if(r + 1 <= n)
                    cur.insert({l, r + 1});
            }
            if(x >= l && x <= r) {
                if(l ^ r) cur.insert({l, r});
                cur.insert({1, 1});
                cur.insert({n, n});
            }
        }

        set<pii> merged;
        for(auto [l, r] : cur) {
            if(merged.empty() || (*--merged.end()).S + 1 < l) {
                merged.insert({l, r});
            } else if((*--merged.end()).S < r) {
                auto pp = (*--merged.end());
                merged.erase(--merged.end());
                merged.insert({pp.F, r});
            }
        }

        int ans = 0;
        for(auto [l, r] : merged) {
            ans += (r - l + 1);
        }
        cout<<ans<<" \n"[q == 0];
        prv = merged;
    }
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