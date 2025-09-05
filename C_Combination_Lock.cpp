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
    if(n & 1) {
        vector<int> ans(n);
        ans[n / 2] = (n + 1) / 2;
        for(int i = 0; i < n / 2; i++) ans[i] = n - i;
        for(int i = n - 1; i > n / 2; i--) ans[i] = n - i;
        for(int i = 0; i < n; i++) cout<<ans[i]<<" \n"[i == n - 1];
    } else {
        cout<<-1<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sz = 9;
    vector<int> tmp(sz);
    iota(tmp.begin(), tmp.end(), 1LL);

    auto chk = [&] {
        vector<int> vis(sz);
        for(int i = 0; i < sz; i++) {
            int cur = tmp[i] - i - 1;
            if(cur < 0) cur += sz;
            if(vis[cur]) return false;
            vis[cur] = 1;
        }
        return true;
    };

    // do {
    //     if(chk()) {
    //         for(int x : tmp) cerr<<x<<" "; cerr<<endl;
    //     }
    // } while(next_permutation(tmp.begin(), tmp.end()));

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}