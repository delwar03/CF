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
const int B = 555;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int l, r, id;
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<Node> que(q);
    int ct = 0;
    for(auto &[l, r, id] : que) {
        cin>>l>>r; --l, --r;
        id = ct++;
    }

    sort(que.begin(), que.end(), [&] (const auto& a, const auto& b) {
        if(a.l / B != b.l / B) return a.l / B < b.l / B;
        return ((a.l / B) & 1 ? a.r < b.r : a.r > b.r);
    });

    vector<int> ans(q), fq(*max_element(v.begin(), v.end()) + 1);
    int lb = 0, rb = -1, cur = 0;

    auto upd = [&] (int x, int del) {
        cur -= fq[x] * (fq[x] - 1) * (fq[x] - 2) / 6;
        fq[x] += del;
        cur += fq[x] * (fq[x] - 1) * (fq[x] - 2) / 6;
    };

    for(auto [l, r, id] : que) {

        while(lb > l) upd(v[--lb], +1);
        while(rb < r) upd(v[++rb], +1);

        while(lb < l) upd(v[lb++], -1);
        while(rb > r) upd(v[rb--], -1);

        ans[id] = cur;
    }

    for(int i : ans) cout<<i<<endl;
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