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
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<pii> ans;

    deque<int> dq(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        int x = dq.front(); dq.pop_front();
        int y = dq.front(); dq.pop_front();
        ans.push_back({x, y});
        dq.push_front(max(x, y));
        dq.push_back(min(x, y));
    }

    // for(auto it : dq) cerr<<it<<" "; cerr<<endl; 

    while(q--) {
        int x; cin>>x;
        if(x <= n) {
            cout<<ans[x - 1].F<<" "<<ans[x - 1].S<<endl;
            continue;
        }
        x -= n;
        x %= (n - 1);
        if(!x) x = n - 1;
        cout<<dq[0]<<" "<<dq[x]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}