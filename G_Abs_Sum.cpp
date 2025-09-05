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
const int BLK = 555;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct BIT {
    vector<int> bit;
    BIT(int n) : bit(n + 1) {}

    void add(int ind, int val) {
        for(int i = ind; i < sz(bit); i += i & -i) bit[i] += val;
    }

    int sum(int ind) {
        if(ind <= 0) return 0;
        int ret = 0;
        for(int i = ind; i; i -= i & -i) ret += bit[i];
        return ret;
    }

    int qur(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

struct Node {
    int x, y, id;
};

vector<int> vals;

void solve() {
    int n; cin>>n;
    vector<int> A(n), B(n);
    for(auto &x : A) cin>>x, vals.push_back(x);
    for(auto &x : B) cin>>x, vals.push_back(x);

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto getId = [&] (int x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    };

    int sz = vals.size();
    for(int i = 0; i < n; i++) A[i] = getId(A[i]), B[i] = getId(B[i]);

    BIT ct_a(sz), ct_b(sz), fa(sz), fb(sz);

    int q, ct = 0; cin>>q;
    vector<Node> qry;
    for(int i = 0; i < q; i++) {
        int x, y; cin>>x>>y;
        qry.push_back({x, y, i});
    }
    sort(qry.begin(), qry.end(), [&] (const auto& a, const auto& b) {
        if(a.x / BLK != b.x / BLK) return a.x / BLK < b.x / BLK;
        return ((a.x / BLK) & 1) ? a.y > b.y : a.y < b.y;
    });

    vector<int> ans(q);
    int lb = 0, rb = -1, cur = 0, sm_a = 0, sm_b = 0;

    auto add_x = [&] (int x, int del) {
        int p = ct_b.sum(a[x + 1] - 1), q = fb.sum(a[x + 1] - 1);
        int tt = rb * A[x + 1] + sm_b - 2 * ((rb - p + 1) * A[x + 1] + q);
        cur += del * tt;
        ct_a.add(a[x], -del);
        fa.add(a[x], -del * A[x]);
        sm_a += -del * A[x];
    };

    auto add_y = [&] (int y, int del) {
        int p = ct_a.sum(b[y] - 1), q = fa.sum(b[y] - 1);
        cerr<<p<<" "<<q<<endl;
        int tt = lb * B[y] + sm_a - 2 * ((lb - p + 1) * B[y] + q);
        cur += del * tt;
        ct_b.add(b[y], del);
        fb.add(b[y], del * B[y]);
        sm_b += del * B[y];
    };

    for(auto [x, y, id] : qry) {
        while(lb > x) add_x(--lb, -1);
        while(rb < y) add_y(++rb, +1);

        while(lb < x) add_x(lb++, +1);
        while(rb > y) add_y(rb--, -1);

        // cerr<<x<<" "<<y<<" "<<id<<endl;

        ans[id] = cur;
    } 

    for(int i : ans) cout<<i<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; ///cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}