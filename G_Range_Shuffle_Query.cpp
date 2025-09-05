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
const int mod = 998244353;
const int N = 3e5 + 10;
const int BLK = 555;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Fact[N], rFact[N], Inv[N];

struct Node {
    int l, r, x, id;
};

void solve() {
    int n, q; cin>>n>>q;
    vector<int> v(n), fq(n + 1), blk_fq(BLK + 10), iF(n + 1, 1), blk_iF(BLK + 10, 1);
    for(auto &x : v) cin>>x;

    vector<Node> que(q);
    for(int i = 0; i < q; i++) {
        int l, r, x; cin>>l>>r>>x;
        --l; --r;
        que[i] = {l, r, x, i};
    }

    sort(que.begin(), que.end(), [&] (const auto& a, const auto& b) {
        if(a.l / BLK != b.l / BLK) return a.l / BLK < b.l / BLK;
        return ((a.l / BLK) & 1 ? a.r < b.r : a.r > b.r);
    });

    vector<int> ans(q);
    int lb = 0, rb = -1;

    for(auto [l, r, x, id] : que) {

        auto upd = [&] (int x, int del) {
            iF[x] = (iF[x] * 1LL * Fact[fq[x]]) % mod;
            blk_iF[x / BLK] = (blk_iF[x / BLK] * 1LL * Fact[fq[x]]) % mod;
            fq[x] += del;
            blk_fq[x / BLK] += del;
            iF[x] = (iF[x] * 1LL * rFact[fq[x]]) % mod;
            blk_iF[x / BLK] = (blk_iF[x / BLK] * 1LL * rFact[fq[x]]) % mod;
        };

        auto get = [&] () {
            int len = 0, rf = 1;
            for(int i = 0; i < BLK && i * BLK < x; i++) {
                int l = i * BLK, r = l + BLK - 1;
                if(r < x) {
                    len += blk_fq[i];
                    rf = (rf * 1LL * blk_iF[i]) % mod;
                } else {
                    for(int j = l; j < x; j++) {
                        len += fq[j];
                        rf = (rf * 1LL * iF[j]) % mod;
                    }
                }
            }

            return (Fact[len] * 1LL * rf) % mod;
        };

        while(lb > l) upd(v[--lb], +1);
        while(rb < r) upd(v[++rb], +1);

        while(lb < l) upd(v[lb++], -1);
        while(rb > r) upd(v[rb--], -1);

        ans[id] = get();
    }

    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Fact[0] = rFact[0] = Inv[1] = 1;

    for(int i = 2; i < N; i++) Inv[i] = mod - (mod / i) * 1LL * Inv[mod % i] % mod;
    for(int i = 1; i < N; i++) {
        Fact[i] = (Fact[i - 1] * 1LL * i) % mod;
        rFact[i] = (rFact[i - 1] * 1LL * Inv[i]) % mod;
    }

    int t = 1; //cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}