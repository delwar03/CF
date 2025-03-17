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
    vector<int> v(n), suf(n);
    for(auto &x : v) cin>>x;

    for(int i = n - 1; i >= 0; i--) suf[i] = (i + 1 < n ? suf[i + 1] : 0) ^ v[i];

    auto get = [&] (int x) {
        for(int i = 32; i >= 0; i--) if(x >> i & 1) {
            return i;
        }
        return -1LL;
    };

    vector<int> pos[32];

    for(int i = 0; i < n; i++) {
        for(int j = get(v[i]); j >= 0; j--) pos[j].push_back(i);
    }

    // for(int i = 0; i <= 5; i++) {
    //     cerr<<i<<" -> ";
    //     for(int j : pos[i]) cerr<<j<<" "; cerr<<endl;
    // }

    while(q--) {
        int x; cin>>x;
        int tmp = x, cur = n;
        while(1) {
            int i = get(tmp);
            if(i == -1) break;
            int j = upper_bound(pos[i].begin(), pos[i].end(), cur - 1) - pos[i].begin() - 1;

            if(j < 0) {cur = 0; break; }

            int pp = pos[i][j];
            if((x ^ (pp + 1 < n ? suf[pp + 1] : 0)) < v[pp]) { cur = pp + 1; break; }
            cur = pos[i][j];
            tmp = x ^ suf[cur];
        }
        cout<<n - cur<<" \n"[q == 0];
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