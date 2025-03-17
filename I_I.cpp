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
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];
    vector<pii> que[n + 1];
    for(int i = 0; i < q; i++) {
        int l, r; cin>>l>>r;
        que[l].push_back({r, i});
    }

    vector<int> pf(n + 1);
    for(int i = 1; i <= n; i++) pf[i] = pf[i - 1] + v[i];

    vector<int> BIT(n + 1);

    auto add = [&] (int x, int val) {
        for(int i = x; i <= n; i += i & -i) BIT[i] += val;
    };

    auto sum = [&] (int x) {
        int ret = 0;
        for(int i = x; i; i -= i & -i) ret += BIT[i];
        return ret;
    };

    auto qur = [&] (int l, int r) {
        if(l > r) return 0LL;
        return sum(r) - sum(l - 1);
    };

    auto upd = [&] (int i, int val) {
        add(i, val - qur(i, i));
    };

    vector<int> ans(q);

    vector<pii> stk;
    for(int i = n; i > 0; i--) {
        while(sz(stk) && stk.back().F <= v[i]) {
            upd(sz(stk), 0);
            stk.pop_back();
        }

        int len = (sz(stk) ? stk.back().S : n) - i;
        stk.push_back({v[i], i});
        add(sz(stk), len * v[i]);

        for(auto [r, id] : que[i]) {
            int lo = 0, hi = sz(stk) - 1, best = -1;
            while(lo <= hi) {
                int mid = lo + hi >> 1;
                if(stk[mid].S <= r) {
                    best = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            int cur = qur(best + 2, sz(stk));
            cur += (r - stk[best].S + 1) * stk[best].F;
            cur -= (pf[r] - pf[i - 1]);

            ans[id] = cur;
        }
    }

    for(auto x : ans) cout<<x<<endl;
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