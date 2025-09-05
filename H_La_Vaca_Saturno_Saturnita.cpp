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

vector<int> di[N];

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    int mx = 0;
    for(auto &x : v) cin>>x, mx = max(mx, x);
    vector<int> pos[mx + 1];
    for(int i = 0; i < n; i++) pos[v[i]].push_back(i);

    function<int(int, int, int)> magic = [&] (int k, int l, int r) {
        if(l > r) return 0LL;
        if(k == 1) return r - l + 1;
        int ret = 0, id = INF;
        for(int j : di[k]) {
            if(j > mx) continue;
            auto it = lower_bound(pos[j].begin(), pos[j].end(), l);
            if(it != pos[j].end() && *it <= r) id = min(id, *it);
        }
        if(id == INF) return (r - l + 1) * k;
        int nk = k;
        while(nk % v[id] == 0) nk /= v[id];
        ret += (id - l) * k + nk + magic(nk, id + 1, r);
        return ret;
    };

    while(q--) {
        int k, l, r; cin>>k>>l>>r;
        --l; --r;
        cout<<magic(k, l, r)<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < N; i++) di[i].push_back(1);

    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i) {
            di[j].push_back(i);
        }
    }

    // for(int i = 1; i <= 10; i++) {
    //     cerr<<i<<" -> ";
    //     for(int j : di[i]) cerr<<j<<" "; cerr<<endl;
    // }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}