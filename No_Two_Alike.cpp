#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
// const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    vector<pii> pos(n + 1, {-1, -1});
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(pos[v[i]].F == -1) pos[v[i]].F = i;
        pos[v[i]].S = i;
    }

    sort(pos.begin(), pos.end());

    vector<pii> tmp;
    for(auto [l, r] : pos) {
        if(l == -1 || l == r) continue;
        if(tmp.empty() || tmp.back().S < l) {
            tmp.push_back({l, r});
        } else {
            auto [ll, rr] = tmp.back(); tmp.pop_back();
            tmp.push_back({ll, max(rr, r)});
        }
    }

    // for(auto [l, r] : tmp) cerr<<l<<" "<<r<<endl; cerr<<endl;

    int ans = 0;
    for(auto [l, r] : tmp) {
        set<int> st(v.begin() + l, v.begin() + r + 1);
        ans += sz(st);
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